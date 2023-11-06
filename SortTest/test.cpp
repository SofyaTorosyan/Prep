#include "pch.h"
#include "gtest/gtest.h"
#include "../../../../../../MySofyasProject/utility.h"
#include "../../../../../../MySofyasProject/sorting.h"

TEST(SortTest, Positive) {
    Sorting s;
    int arr1[] = { 1, 0, 0, -1, 2 };
    int original1[] = { 1, 0, 0, -1, 2 };
    int size = 5;
    EXPECT_TRUE(s.checkAllSorts(arr1, original1, size));

    int arr2[1] = { 2 };
    int original2[1] = { 2 };
    size = 1;
    EXPECT_TRUE(s.checkAllSorts(arr2, original2, size));

    int arr3[10] = { -1, -1, -1, 10, 2, 0, 1, 99, 100, 1 };
    int original3[10] = { -1, -1, -1, 10, 2, 0, 1, 99, 100, 1 };
    size = 10;
    EXPECT_TRUE(s.checkAllSorts(arr3, original3, size));

    int arr4[4] = { 5, 4, 3, 2};
    int original4[4] = { 5, 4, 3, 2 };
    size = 4;
    EXPECT_TRUE(s.checkAllSorts(arr4, original4, size));

    int arr5[4] = { 1, 2, 3, 4 };
    int original5[4] = {1, 2, 3, 4 };
    size = 4;
    EXPECT_TRUE(s.checkAllSorts(arr5, original5, size));
}
/*
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/