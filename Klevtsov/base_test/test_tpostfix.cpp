#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, can_create_based_in_expression)
{
	ASSERT_NO_THROW(TPostfix p("a + b"));
}

TEST(TPostfix, can_get_infix)
{
	TPostfix p;
	string infix = "( a + b ) * c";
	p.ToPostfix(infix);
	ASSERT_NO_THROW(p.GetInfix());
	EXPECT_EQ(infix, p.GetInfix());
}

TEST(TPostfix, can_get_postfix)
{
	TPostfix p;
	string infix = "( a + b ) * c";
	string postfix = "a b + c *";
	p.ToPostfix(infix);
	ASSERT_NO_THROW(p.GetPostfix());
	EXPECT_EQ(postfix, p.GetPostfix());
}

TEST(TPostfix, can_transform_infix_to_postfix)
{
	TPostfix p;
	string infix = "a * b + sin ( cos ( p + b ) - ( a + b ) * c )";
	string postfix = "a b * p b + cos a b + c * - sin +";
	ASSERT_NO_THROW(p.ToPostfix(infix));
	EXPECT_EQ(postfix, p.GetPostfix());
}

TEST(TPostfix, can_calculate)
{
	TPostfix p;
	string infix = "( 2.0 ^ 2 + ( 1 + 2 ) * 3 + 1 ) * 4";
	p.ToPostfix(infix);
	EXPECT_EQ(56, p.Calculate());
}