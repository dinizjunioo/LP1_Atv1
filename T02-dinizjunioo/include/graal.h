/*!
 * @author Diniz Rodrigues da Silva Junior
 * @date April 21th, 2022.
 */

#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;

namespace graal
{

    /*!
     * Finds and returns a pair with the smallest and greatest elements in a range.
     *
     * @tparam Itr Iterator to the range.
     * @tparam Compare A regular comparison function.Comparison functor.
     *
     * @param first_ Pointer to the first element of the range we want to copy (inclusive).
     * @param last_ Pointer to the last element of the range we want to copy (exclusive).
     * @param cmp The comparison function that return true if the first element is *less* than the second.
     *
     * @return A pair of the smallest and greatest elements.
     *
     */
    template <typename Itr, typename Compare>
    std::pair<Itr, Itr> minmax(Itr first, Itr last, Compare cmp)
    {
        /*!
         * Edite esse arquivo para incluir suas respostas.
         * @param maior recebe o maior valor dentro do while em uma busca linear
         * @param menor recebe o menor valor dentro do while em uma busca linear
         * @param make_pair  retorna um par de Itr com os valores {menor,maior}
         */
        auto menor = *first;
        auto maior = *first;

        while (first != last)
        {
            if (*first > maior)
                maior = *first;
            if (*first < menor)
                menor = *first;
            *first++;
        }
        return std::make_pair(menor, maior);
    }

    template <class BidirIt>
    void reverse(BidirIt first, BidirIt last)
    {

        /*!
         * @param a se a media for um numero par então o parametro 'a' se encarregara
         * de entrar em um if apenas uma vez, no próposito de ter um swap a mais no programa
         * Se o numero for impar, então esse 'if a mais' será ignorado
         * @param num recebe o valor mediano do vector
         * @param i é um contador, enquanto ele nao chegar no valor medio, continue a executar
         * o swap.
         * @param last-1 --> foi usado para criar um conjunto fechado.
         */

        last = last - 1;
        bool a = true;
        auto num = (last - first) / 2;
        auto i = 0;
        while (i != num)
        {
            if (a && (num % 2 != 0))
            {
                std::swap(*first, *last);
                first++;
                last--;
                a = false;
            }
            else
            {
                std::swap(*first, *last);
                first++;
                last--;
                i++;
            }
        }
    }

    template <class InputIt>
    InputIt copy(InputIt first, InputIt last,
                 InputIt d_first)
    {
        /*!
         * pega o endereço do first do vetor a ser copiado e do vetor a receber
         * as copias e faz a copia dos dados propriamente dito.
         */

        while (first != last)
        {
            *d_first = *first; // copiar os dados

            *d_first++; // avança para o próximo indice
            *first++;   // avança para o próximo indice
        }
        return d_first; // retorna o ultimo elemento copiado
    }

    template <class InputIt, class UnaryPredicate>
    InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
    {
        /*!
         * @param pred se esse prod se tornar verdadeiro em algum momento do while
         * significa que achou o que estava procurando, caso contrário retornará falso.
         */
        bool pred = false; // se p se torna verdadeiro entao existe
                           // o predicado no vector
        while (first != last)
        {
            p == *first ? pred = true : pred = false;
            if (pred == true)
                return first;
            *first++;
        }
        return last; // como nenhum predicado foi encontrado, retorna o last
    }

    template <class InputIt, class UnaryPredicate>
    bool all_of(InputIt first, InputIt last, UnaryPredicate p)
    {
        /*!
         * @param pred se esse prod se tornar falso em algum momento do while
         * significa a tautologia é falsa, logo todos nao sao iguais.
         */
        bool pred = true;
        while (first != last)
        {
            p == *first ? pred = true : pred = false;
            if (pred == false)
                return false;
            *first++;
        }
        return true;
    }

    template <class InputIt, class UnaryPredicate>
    bool any_of(InputIt first, InputIt last, UnaryPredicate p)
    {
        /*!
         * @param pred se esse prod se tornar verdadeiro em algum momento do while
         * significa que existe ao menos um predicado que estava sendo
         * procurado.
         */
        bool pred = false;
        while (first != last) // percorrendo o vector
        {
            p == *first ? pred = true : pred = false; // se achar algum preditado no range
            if (pred == true)                         // muda o p pra true e retonar true
                return true;
            *first++;
        }
        return false;
    }

    template <class InputIt, class UnaryPredicate>
    bool none_of(InputIt first, InputIt last, UnaryPredicate p)
    {
        /*!
         * @param pred se esse prod se tornar verdadeiro em algum momento do while
         * significa que contradição é falsa, tal qual existe ao menos um predicado verdadeiro.
         */
        bool pred = true;
        while (first != last)
        {
            p != *first ? pred = true : pred = false;
            if (pred == false)
                return false;
            *first++;
        }

        return true;
    }

    template <class InputIt1, class InputIt2, class Equal>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2,
               Equal eq)
    {
        /*!
         * @param p se esse prod se tornar falso em algum momento do while
         * significa que acho um predicado diferente no vector.
         * @param num é apartir desse indice que começará a comparação
         */
        bool p = true;
        auto num = first2 + (last - first);
        while (first2 != num)
        {
            cout << *num;
            *first2 == *num ? p = true : p = false;
            if (p == false)
                return false;
            *first2++;
        }
        return true;
    }

    template <class InputIt1, class InputIt2, class Equal>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2, InputIt2 last2,
               Equal eq)
    {
        /*!
         * @param p se esse prod se tornar falso em algum momento do while
         * significa que acho um predicado diferente no vector.
         * Caso isso aconteça, então esses vetores não são totalmente iguais
         */
        bool p = true;
        while (first != last)
        {
            // n sei como usar esse eq
            // if !(eq(*first,*first2))
            // p = false;
            // else
            // p = true;

            *first == *first2 ? p = true : p = false;
            if (p == false)
                return false;
            *first++;
            *first2++;
        }
        return true;
    }

    template <class InputIt, class Equal>
    InputIt unique(InputIt first, InputIt last, Equal eq)
    {
        /*!
         * @param find vai ser o indice tanto para verificar se o numero é igual ao posterior, quanto como indice inicial
         * para @param i tal qual faz as trocas até 'last-first', levando tudo para a direita e "eliminando" a igualdade.
         * @param slow serve para verificar se existe uma tautologia, enquanto o first incrementa, o slow fica estatico fazendo os teste de verificação
         * com o auxilio do contador @param count.
         *        */
        value_type find = 1;
        value_type count = 0;
        auto slow = first;

        // verifica se é uma tautologia
        while (*first != *last)
        {
            slow[0] == slow[count + 1] ? count++ : slow[find] == slow[count + 1];
            first++;
        }

        while (*first != *last)
        {
            if (first[find] == *first) // se encontrou um numero igual, entao faça as sucessivas trocas da direita para a esquerda
            {
                for (auto i = find; i != (last - first); i++)
                    first[i] = first[i + 1];

                *first++;
                count += 1;
                find = 0;
            }

            if (first[find] == *last) // para não entrar em loop infinito
            {
                *first++;
                find = 0;
            }
            find++;
        }

        last = last - count; // retorna quantos indice o last tem que andar para a esquerda

        return last;
    }

    template <class ForwardIt, class UnaryPredicate>
    ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
    {

        last = last - 1;
        /*!
         * Se @param p for maior que o last ou menor que o first, sigfinica que não há o que particionar
         */
        if (p > *last || *first > p)
            return first;

        /*!
         * Se @param p for maior que o first, então trago o last até o primeiro indice maior que p e faço o swap do first com o last

         */

        if (p > *first)
        {
            last = last - p + 1;
            cout << *fast;

            while (last != fast)
            {
                std::swap(*first, *last);
                first++;
                last++;
            }
        }
        first++;

        return first;
    }

} // namespace graal.

#endif
