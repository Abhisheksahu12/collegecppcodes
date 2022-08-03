#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Set
{
    vector<int> S; // Big S is the private member of each Set class!

public:
    Set(vector<int> s1)
    {
        this->S = s1;
    }
    bool ismember(int elem)
    { // useful in Union,Intersection,Subset,Differences,PowerSet
        for (int i : S)
        {
            if (elem == i)
                return 1;
        }

        return 0;
    }

    void intersection(Set s)
    {
        for (int i : S)
        {
            if (s.ismember(i))
                cout << i << " ";
        }
        cout << "\n";
    }

    void Union(Set s)
    {
        for (int i : S)
            cout << i << " ";

        for (int j : s.S)
        {
            if (!(ismember(j)))
            {
                cout << j << " ";
            }
        }
    }

    bool IsSubset(Set s)
    {
        for (int i : s.S)
        {
            if (!(ismember(i)))
                return false;
        }
        return true;
    }

    void powerset()
    {
        for (int i = 0; i < pow(2, S.size()); i++)
        {
            cout << "{ ";
            for (int k = 0; k < S.size(); k++)
            {
                if (i & (1 << k))
                {
                    cout << S[k] << " ";
                }
            }
            cout << " }" << endl;
        }
    }

    void Cartesian_Product(Set s)
    {
        cout << "{ ";
        for (int i = 0; i < S.size(); i++)
        {
            for (int j = 0; j < s.S.size(); j++)
            {

                cout << "{" << S[i] << "," << s.S[j] << "}";
            }
            cout << " , ";
        }
        cout << " }";
    }

    void set_difference(Set s)
    {
        cout << "{ ";
        for (int i : S)
        {
            if (!(s.ismember(i)))
                cout << i << ",";
        }
        cout << " }";
    }

    void symmetric_difference(Set s)
    {
        cout << "{ ";
        for (int i : S)
        {
            if (!s.ismember(i))
                cout << i << " , ";
        }
        for (int j : s.S)
        {
            if (!ismember(j))
                cout << j << " ";
        }
        cout << " }";
    }
};

// class relation
// {
//     bool **rel;
//     int dno, rno;

// public:
//     relation(int domain, int range)
//     {
//         this->dno = domain;
//         this->rno = range;
//         this->rel[domain][range];
//         for (int i = 0; i < domain; i++)
//         {
//             for (int j = 0; j < range; j++)
//             {
//                 cin >> this->rel[i][j];
//             }
//         }
//     }

//     bool is_reflexive()
//     {
//         int big = (rno > dno) ? rno : dno;
//         for (int i = 0; i < big; i++)
//         {
//             if (!(rel[i][i] == 1))
//                 return false;
//         }
//         return true;
//     }

//     bool is_symmetric()
//     {
//         for (int i = 0; i < dno; i++)
//         {
//             for (int j = 0; j < rno; j++)
//             {
//                 if (!(j > i && rel[i][j] == 0))
//                 {
//                     if (rel[i][j] != rel[j][i])
//                     {
//                         return false;
//                     }
//                 }
//             }
//         }
//         return true;
//     }

//     bool is_transitive()
//     {
//         for (int i = 0; i < dno; i++)
//         {
//             for (int j = 0; j < rno; j++)
//             {
//                 if (i != j && rel[i][j])
//                 {
//                     for (int k = 0; k < rno; k++)
//                     {
//                         if (rel[j][k])
//                         {
//                             if (!rel[i][k])
//                             {
//                                 return false;
//                             }
//                             else
//                                 continue;
//                         }
//                     }
//                 }
//             }
//         }
//         return true;
//     }

//     bool is_antisymm()
//     {
//         for (int i = 0; i < dno; i++)
//         {
//             for (int j = 0; j < rno; j++)
//             {
//                 if (!i == j)
//                 {
//                     if (rel[i][j])
//                     {
//                         if (rel[j][i])
//                         {
//                             return false;
//                         }
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };

int main()
{
    // Set Operations from here
    Set s1({1, 2, 3}), s2({2, 3, 4});
    cout << s1.ismember(1) << endl;
    s1.intersection(s2);
    cout << endl;
    s1.Union(s2);
    cout << s1.IsSubset(s2) << endl;
    s1.Cartesian_Product(s2);
    cout << endl;
    s1.set_difference(s2);
    cout << endl;
    s1.symmetric_difference(s2);
    cout << endl;
    s1.powerset();
    cout << endl;
    // Set Operations end here

    // Relation Operation starts here
    // relation r(3, 2);
    // cout << r.is_reflexive() << endl;
    // cout << r.is_symmetric() << endl;
    // cout << r.is_transitive() << endl;

    return 0;
}
