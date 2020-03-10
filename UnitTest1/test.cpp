#include <array>
#include "pch.h"

#include "../lib/words.h"
#include "../lib/list.h"
#include "../lib/bit_number.h"
#include "../lib/tree.h"


namespace test
{
    TEST(WordsTest, calcWordLenghts_Test1)
    {
        const std::string str = "Hello, i am string";
        const auto actual = calcWordLenghts(str);
        const decltype(actual) expected =
        {
            { 1, 1 },
            { 2, 1 },
            { 5, 1 },
            { 6, 1 },
        };
        EXPECT_EQ(expected, actual);
    }

    TEST(WordsTest, calcWordLenghts_Test2)
    {
        const std::string str = "Hello, i am string\nHow are you ? \nAll OK";
        const auto actual = calcWordLenghts(str);
        const decltype(actual) expected =
        {
            { 1, 1 },
            { 2, 2 },
            { 3, 4 },
            { 5, 1 },
            { 6, 1 },
        };
        EXPECT_EQ(expected, actual);
    }

    TEST(WordsTest, calcWordLenghts_Test3)
    {
        const std::string str = "Terminator T1000";
        const auto actual = calcWordLenghts(str);
        const decltype(actual) expected =
        {
            { 10, 1 },
            { 5, 1 },
        };
        EXPECT_EQ(expected, actual);
    }

    TEST(ListTest, filter5_Test)
    {
        List lst(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);
        lst.push_back(6);
        lst.push_back(7);
        lst.push_back(8);
        lst.push_back(9);
        lst.push_back(10);

        lst.filter5();

        const std::vector<SomeDateType> expected = { 1,2,3,4,6,7,8,9 };
        auto head = &lst;
        unsigned int counter = 0;
        while (head->next_)
        {
            EXPECT_EQ(head->payload_, expected.at(counter));
            head = head->next_;
            counter++;
        }
    }

    TEST(BitNumberTest, getMinMaxBit_Test1)
    {
        // 101 -> min 011 = 3 
        const auto [min, max] = getMinMaxBit(5);
        EXPECT_EQ(static_cast<uint32_t>(3), min);
    }

    TEST(BitNumberTest, getMinMaxBit_Test2)
    {
        // 1111111.. -> 111111...
        const auto [min, max] = getMinMaxBit(std::numeric_limits<uint32_t>::max());
        EXPECT_EQ(std::numeric_limits<uint32_t>::max(), max);
        EXPECT_EQ(std::numeric_limits<uint32_t>::max(), min);
    }

    TEST(BitNumberTest, getMinMaxBit_Test3)
    {
        // 0000001 -> 10000
        const auto [min, max] = getMinMaxBit(1);
        EXPECT_EQ(std::numeric_limits<uint32_t>::max() / 2 + 1, max);
        EXPECT_EQ(static_cast<uint32_t>(1), min);
    }

    TreeNode* newNode(int i)
    {
        TreeNode* node = new TreeNode(i);
        node->leftChild = nullptr;
        node->rightChild = nullptr;

        return node;
    }

    TEST(TreeTest, getDepht_Test)
    {
        TreeNode* root = newNode(0);

        root->leftChild = newNode(1);
        root->rightChild = newNode(2);
        root->leftChild->leftChild = newNode(3);
        root->leftChild->rightChild = newNode(4);

        const auto [actual, nodes] = getDepht(root);
        EXPECT_EQ(actual, 3);
        EXPECT_EQ(nodes.size(), 2);
        EXPECT_EQ(nodes.at(0)->number, 3);
        EXPECT_EQ(nodes.at(1)->number, 4);
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}