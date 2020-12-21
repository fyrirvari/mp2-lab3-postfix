#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, cant_create_stack_with_too_large_length)
{
	ASSERT_ANY_THROW(TStack<int> st(MAX_STACK_SIZE + 1));
}

TEST(TStack, can_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> st(5);
	ASSERT_NO_THROW(TStack<int> st1(st));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; ++i)
		st.push(i);
	TStack<int> st1(st);
	EXPECT_EQ(st, st1);
}

TEST(TStack, can_get_size)
{
	TStack<int> st;
	EXPECT_EQ(true, st.empty());
	for (int i = 0; i < 5; ++i)
		st.push(i);
	EXPECT_EQ(5, st.size());
}

TEST(TStack, can_get_boolean_if_the_stack_is_full)
{
	TStack<int> st(MAX_STACK_SIZE);
	EXPECT_EQ(false, st.full());
	for (int i = 0; i < MAX_STACK_SIZE; ++i)
		st.push(i);
	EXPECT_EQ(true, st.full());
}

TEST(TStack, can_get_boolean_if_the_stack_is_empty)
{
	TStack<int> st;
	EXPECT_EQ(true, st.empty());
	st.push(0);
	EXPECT_EQ(false, st.empty());
}

TEST(TStack, can_push_and_pop_element)
{
	TStack<int> st;
	ASSERT_NO_THROW(st.push(10));
	EXPECT_EQ(10, st.pop());
}

TEST(TStack, can_peek_element)
{
	TStack<int> st;
	ASSERT_NO_THROW(st.push(10));
	EXPECT_EQ(10, st.peek());
}

TEST(TStack, cant_push_element_when_stack_is_overflow)
{
	TStack<int> st(MAX_STACK_SIZE);
	for (int i = 0; i < MAX_STACK_SIZE; ++i)
		st.push(i);
	ASSERT_ANY_THROW(st.push(10));
}

TEST(TStack, cant_pop_element_when_stack_is_underflow)
{
	TStack<int> st;
	ASSERT_ANY_THROW(st.pop());
}

TEST(TStack, cant_search_a_nonexistent_item)
{
	TStack<int> st;
	for (int i = 0; i < 10; ++i)
		st.push(i);
	EXPECT_EQ(-1, st.search(10));
}

TEST(TStack, can_search_an_existing_item)
{
	TStack<int> st;
	for (int i = 0; i < 10; ++i)
		st.push(i);
	int qty = st.search(3);
	for (int i = 0; i < qty; ++i)
		st.pop();
	EXPECT_EQ(3, st.peek());
}

TEST(TStack, can_clear_stack)
{
	TStack<int> st;
	for (int i = 0; i < 10; ++i)
		st.push(i);
	st.clear();
	EXPECT_EQ(true, st.empty());
}


TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> st;
	ASSERT_NO_THROW(st = st);
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> st;
	TStack<int> st1;
	EXPECT_EQ(st.size(), st1.size());
	for (int i = 0; i < 5; i++)
		st.push(i);
	EXPECT_EQ(st, st1 = st);
}

TEST(TStack, assign_operator_change_stack_size)
{
	TStack<int> st;
	TStack<int> st1;
	st.push(0);
	EXPECT_NE(st.size(), st1.size());
	st = st1;
	EXPECT_EQ(st.size(), st1.size());
}

TEST(TStack, can_assign_stacks_of_different_size)
{
	TStack<int> st;
	TStack<int> st1;
	for (int i = 0; i < 10; i++)
		st1.push(i);
	EXPECT_NE(st.size(), st1.size());
	EXPECT_EQ(st1, st = st1);
}


TEST(TStack, compare_equal_stacks_return_true)
{
	TStack<int> st;
	for (int i = 0; i < 10; i++)
		st.push(i);
	TStack<int> st1(st);
	EXPECT_EQ(true, st1 == st);
}

TEST(TStack, compare_stack_with_itself_return_true)
{
	TStack<int> st;
	for (int i = 0; i < 10; i++)
		st.push(i);
	EXPECT_EQ(true, st == st);
}

TEST(TStack, stacks_with_different_size_are_not_equal)
{
	TStack<int> st;
	TStack<int> st1;
	st.push(0);
	EXPECT_NE(st.size(), st1.size());
	EXPECT_EQ(true, st != st1);
}