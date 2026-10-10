#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstddef>
#include <cstdlib>

// Trie 'l' (valeurs uniques) par Ford-Johnson.
// A integrer dans PmergeMe comme methode privee (static ou non).
// Chaque appel a ses propres variables locales : paires, straggler, chaine.
static void mergeInsert(std::list<int> &l)
{
    if (l.size() < 2)
        return;

    // 1. Paires locales a CE niveau (first = grand, second = petit)
    bool hasStraggler = (l.size() % 2 != 0);
    int straggler = 0;
    std::vector<std::pair<int, int> > pairs;

    std::list<int>::iterator it = l.begin();
    while (it != l.end())
    {
        int a = *it;
        ++it;
        if (it == l.end())
        {
            straggler = a; // dernier element seul
            break;
        }
        int b = *it;
        ++it;
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    // 2. On extrait les grands et on trie RECURSIVEMENT
    std::list<int> winners;
    for (std::size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);
    mergeInsert(winners);

    // 3. Le LIEN : la valeur du grand (unique) identifie sa paire.
    //    sorted[i] = la paire dont le grand est le i-eme grand trie.
    std::vector<std::pair<int, int> > sorted;
    for (it = winners.begin(); it != winners.end(); ++it)
    {
        for (std::size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == *it)
            {
                sorted.push_back(pairs[j]);
                break;
            }
        }
    }

    // 4. Chaine principale : b1, a1, a2, ..., ak
    std::list<int> chain = winners;
    chain.push_front(sorted[0].second);

    // 5. Insertion des b_i (i >= 2, 1-based) dans l'ordre de Jacobsthal
    const std::size_t k = sorted.size();
    std::size_t jPrev = 1;
    std::size_t jCur = 3;
    while (jPrev < k)
    {
        std::size_t upper = (jCur < k) ? jCur : k;
        for (std::size_t i = upper; i > jPrev; --i)
        {
            int a = sorted[i - 1].first;
            int b = sorted[i - 1].second;
            std::list<int>::iterator limit = std::find(chain.begin(), chain.end(), a);
            std::list<int>::iterator pos = std::lower_bound(chain.begin(), limit, b);
            chain.insert(pos, b);
        }
        std::size_t jNext = jCur + 2 * jPrev;
        jPrev = jCur;
        jCur = jNext;
    }

    // 6. Straggler : dichotomie sur toute la chaine
    if (hasStraggler)
    {
        std::list<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }

    l = chain;
}

// ---- test ----
int main()
{
    for (std::size_t n = 0; n <= 300; ++n) 
    {
        std::vector<int> base;
        for (std::size_t i = 0; i < n; ++i)
            base.push_back(static_cast<int>(i) * 7 + 2);
        std::random_shuffle(base.begin(), base.end());

        std::list<int> l(base.begin(), base.end());
        mergeInsert(l);
        
        std::vector<int> expected(base);
        std::sort(expected.begin(), expected.end());
        if (!std::equal(l.begin(), l.end(), expected.begin()) || l.size() != n)
        {
            std::cout << "ECHEC pour n = " << n << std::endl;
            return 1;
        }
    }
    std::cout << "OK : list triee pour n = 0..300" << std::endl;
    return 0;
}