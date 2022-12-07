// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_push_front) {
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    List<int>::Iterator itr = list.begin();
    ASSERT_EQUAL(*itr, 1);
    ++itr;
    ASSERT_EQUAL(*itr, 2);
    ++itr;
    ASSERT_EQUAL(*itr, 3);
}

TEST(test_push_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    List<int>::Iterator itr = list.begin();
    ASSERT_EQUAL(*itr, 1);
    ++itr;
    ASSERT_EQUAL(*itr, 2);
    ++itr;
    ASSERT_EQUAL(*itr, 3);
}

TEST(test_front) {
    List<int> list;

    list.push_front(3);
    ASSERT_EQUAL(list.front(), 3);

    list.push_front(2);
    ASSERT_EQUAL(list.front(), 2);

    list.push_front(1);
    ASSERT_EQUAL(list.front(), 1);
}

TEST(test_back) {
    List<int> list;

    list.push_back(1);
    ASSERT_EQUAL(list.back(), 1);

    list.push_back(2);
    ASSERT_EQUAL(list.back(), 2);

    list.push_back(3);
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_empty) {
    List<int> list;
    ASSERT_TRUE(list.empty());
}

TEST(test_pop_front) {
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    list.pop_front();
    ASSERT_EQUAL(list.front(), 2);
    list.pop_front();
    ASSERT_EQUAL(list.front(), 3);
    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST(test_pop_front_sing_elem) {
    List<int> list;
    list.push_back(1);

    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST(test_pop_back_singl_elem) {
    List<int> list;
    list.push_front(1);

    list.pop_back();
    ASSERT_TRUE(list.empty());
}

TEST(test_pop_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_back();
    ASSERT_EQUAL(list.back(), 2);
    list.pop_back();
    ASSERT_EQUAL(list.back(), 1);
    list.pop_back();
    ASSERT_TRUE(list.empty());
}

TEST(test_size_back) {
    List<int> list;
    ASSERT_EQUAL(list.size(), 0);
    list.push_back(1);
    ASSERT_EQUAL(list.size(), 1);
    list.push_back(2);
    ASSERT_EQUAL(list.size(), 2);
    list.push_back(3);
    ASSERT_EQUAL(list.size(), 3);
    list.pop_back();
    ASSERT_EQUAL(list.size(), 2);
    list.pop_back();
    ASSERT_EQUAL(list.size(), 1);
    list.pop_back();
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_size_front) {
    List<int> list;
    ASSERT_EQUAL(list.size(), 0);
    list.push_front(1);
    ASSERT_EQUAL(list.size(), 1);
    list.push_front(2);
    ASSERT_EQUAL(list.size(), 2);
    list.push_front(3);
    ASSERT_EQUAL(list.size(), 3);
    list.pop_front();
    ASSERT_EQUAL(list.size(), 2);
    list.pop_front();
    ASSERT_EQUAL(list.size(), 1);
    list.pop_front();
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_size_mixed) {
    List<int> list;
    ASSERT_EQUAL(list.size(), 0);
    list.push_front(1);
    ASSERT_EQUAL(list.size(), 1);
    list.push_back(2);
    ASSERT_EQUAL(list.size(), 2);
    list.push_front(3);
    ASSERT_EQUAL(list.size(), 3);
    list.pop_back();
    ASSERT_EQUAL(list.size(), 2);
    list.pop_front();
    ASSERT_EQUAL(list.size(), 1);
    list.pop_back();
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_clear) {
    List<int> list;
    list.push_back(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    
    list.clear();
    ASSERT_TRUE(list.empty());
}

TEST(test_assignment_operator) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    List<int> list2;
    list2.push_back(4);
    list2.push_back(5);
    list2 = list1;

    List<int>::Iterator itr = list2.begin();
    ASSERT_EQUAL(*itr, 1);
    ++itr;
    ASSERT_EQUAL(*itr, 2);
    ++itr;
    ASSERT_EQUAL(*itr, 3);
}

TEST(test_copy_ctor) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    List<int> list2(list1);

    List<int>::Iterator itr = list2.begin();
    ASSERT_EQUAL(*itr, 1);
    ++itr;
    ASSERT_EQUAL(*itr, 2);
    ++itr;
    ASSERT_EQUAL(*itr, 3);
}

TEST(itr_plus) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator itr = list.begin();
    List<int>::Iterator itr_end = list.end();

    ASSERT_EQUAL(*itr, 1);
    ++itr;
    ASSERT_EQUAL(*itr, 2);
    ++itr;
    ASSERT_EQUAL(*itr, 3);
    ++itr;
    ASSERT_TRUE(itr == itr_end);
}

TEST(itr_minus) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator itr = list.begin();

    ++itr;
    ++itr;
    ASSERT_EQUAL(*itr, 3);
    --itr;
    ASSERT_EQUAL(*itr, 2);
    --itr;
    ASSERT_EQUAL(*itr, 1);
}

TEST(itr_erase) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator itr = list.begin();

    ++itr;
    list.erase(itr);
    List<int>::Iterator itr_new = list.begin();
    ASSERT_EQUAL(*itr_new, 1);
    ++itr_new;
    ASSERT_EQUAL(*itr_new, 3);
    ASSERT_EQUAL(list.size(), 2);
}

TEST(itr_erase_first) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator itr = list.begin();

    list.erase(itr);
    List<int>::Iterator itr_new = list.begin();
    ASSERT_EQUAL(*itr_new, 2);
    ++itr_new;
    ASSERT_EQUAL(*itr_new, 3);
    ASSERT_EQUAL(list.size(), 2);
}

TEST(itr_erase_last) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator itr = list.begin();

    ++itr;
    ++itr;
    list.erase(itr);
    List<int>::Iterator itr_new = list.begin();
    ASSERT_EQUAL(*itr_new, 1);
    ++itr_new;
    ASSERT_EQUAL(*itr_new, 2);
    ++itr_new;
    ASSERT_TRUE(itr_new == list.end());
    ASSERT_EQUAL(list.size(), 2);
}

TEST(itr_erase_single_elem) {
    List<int> list;
    list.push_back(1);
    List<int>::Iterator itr = list.begin();

    list.erase(itr);
    ASSERT_TRUE(list.empty());
}

TEST(itr_insert) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    List<int>::Iterator itr = list.begin();

    ++itr;
    list.insert(itr, 2);
    List<int>::Iterator itr_new = list.begin();
    ASSERT_EQUAL(*itr_new, 1);
    ++itr_new;
    ASSERT_EQUAL(*itr_new, 2);
    ++itr_new;
    ASSERT_EQUAL(*itr_new, 3);
    ASSERT_EQUAL(list.size(), 3);
}

TEST(itr_insert_first) {
    List<int> list;
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator itr = list.begin();

    list.insert(itr, 1);
    List<int>::Iterator itr_new = list.begin();
    ASSERT_EQUAL(*itr_new, 1);
    ++itr_new;
    ASSERT_EQUAL(*itr_new, 2);
    ++itr_new;
    ASSERT_EQUAL(*itr_new, 3);
    ASSERT_EQUAL(list.size(), 3);
}

TEST(itr_insert_single_elem) {
    List<int> list;
    list.push_back(2);
    List<int>::Iterator itr = list.begin();

    list.insert(itr, 1);
    List<int>::Iterator itr_new = list.begin();
    ASSERT_EQUAL(*itr_new, 1);
    ++itr_new;
    ASSERT_EQUAL(*itr_new, 2);
    ASSERT_EQUAL(list.size(), 2);
}

TEST(list_push_string) {
    List<string> list; // {front, apple, orange, end}
    list.push_front("apple");
    list.push_back("orange");
    list.push_back("end");
    list.push_front("front");
    List<string>::Iterator itr = list.begin();

    ASSERT_EQUAL(list.size(), 4);
    ASSERT_EQUAL(*itr, "front");
    ++itr;
    ASSERT_EQUAL(*itr, "apple");
    ++itr;
    ASSERT_EQUAL(*itr, "orange");
    ++itr;
    ASSERT_EQUAL(*itr, "end");

    ASSERT_EQUAL(list.front(), "front");
    ASSERT_EQUAL(list.back(), "end");
}

TEST(list_pop_string) {
    List<string> list; // {front, apple, orange, end}
    list.push_front("apple");
    list.push_back("orange");
    list.push_back("end");
    list.push_front("front");

    list.pop_front();
    list.pop_back();
    List<string>::Iterator itr = list.begin();

    ASSERT_EQUAL(*itr, "apple");
    ++itr;
    ASSERT_EQUAL(*itr, "orange");
}

TEST(list_insert_string) {
    List<string> list;
    list.push_back("front");
    list.push_back("end");

    List<string>::Iterator itr = list.begin();
    ++itr;
    list.insert(itr, "insert");
    List<string>::Iterator itr_new = list.begin();
    ++itr_new;
    ASSERT_EQUAL(*itr_new, "insert");
    ASSERT_EQUAL(list.size(), 3);
}

TEST(list_erase_string) {
    List<string> list;
    list.push_back("front");
    list.push_back("erase");
    list.push_back("end");

    List<string>::Iterator itr = list.begin();
    ++itr;
    list.erase(itr);
    List<string>::Iterator itr_new = list.begin();
    ASSERT_EQUAL(*itr_new, "front");
    ++itr_new;
    ASSERT_EQUAL(*itr_new, "end");
    ASSERT_EQUAL(list.size(), 2);
}

TEST_MAIN()
