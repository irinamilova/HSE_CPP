#include <iostream>
#include <string>
#include <vector>
#include <cmath>


struct Vector {
    std::string word;
    std::vector<int> vector;
};

int Product(const std::vector<int>& v1, const std::vector<int>& v2)
{
    int product = 0;
    for (size_t x = 0; x < v1.size(); ++x)
    {
        product += v1[x] * v2[x];
    }
    return product;
}

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::vector<Vector> words(m);

    for (int x = 0; x < m; ++x)
    {
        std::cin >> words[x].word;
        words[x].vector.resize(n);
        for (int y = 0; y < n; ++y)
        {
            std::cin >> words[x].vector[y];
        }
    }
    std::vector<int> first = words[0].vector;
    int maxi = -1;
    std::vector<std::string> similars;

    for (int x = 1; x < m; ++x)
    {
        int product = Product(first, words[x].vector);
        if (product > maxi)
        {
            maxi = product;
            similars.clear();
            similars.push_back(words[x].word);
        }
        else if (product == maxi)
        {
            similars.push_back(words[x].word);
        }
    }
    for (const auto& word: similars)
    {
        std::cout << word << std::endl;
    }
    return 0;
}
