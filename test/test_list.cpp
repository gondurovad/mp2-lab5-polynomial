#include <gtest.h>
#include "list.h"
#include "polynomial.h"


TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> list);
}

TEST(List, can_create_copied_list)
{
	List<int> list;
	list.Insert(5);
	List<int> copy(list);

	EXPECT_EQ(list.GetFirst()->GetData(), copy.GetFirst()->GetData());
}

TEST(List, can_insert_node_in_list)
{
	List<int> list;
	const int c = 9;

	list.Insert(c);

	EXPECT_EQ(c, (list.GetFirst())->GetData());
}

TEST(List, can_delete_node)
{
	const int c = -2;
	List<int> list;

	list.Insert(c);
	list.Insert(-2);
	list.Insert(9);

	list.Delete(list.GetFirst()->GetNext());

	EXPECT_EQ(c, (list.GetFirst()->GetNext())->GetData());
}

TEST(List, check_length_of_list_after_join)
{
	List<int> list1, list2;
	const int l1 = 2, l2 = 1, res = 3;

	list1.Insert(1); 
	list1.Insert(2); 
	list2.Insert(3); 

	list1.Join(list2);

	EXPECT_EQ(res, list1.GetLength());
}

TEST(List, check_list_is_sorted_after_join)
{
	List<int> list1, list2;
	const bool res = true;

	list1.Insert(5); list1.Insert(0);
	list2.Insert(3);

	list1.Join(list2);

	EXPECT_EQ(res, list1.IsSort());
}


//____________

TEST(Monom, can_create_monom)
{
	ASSERT_NO_THROW(Monom m(9.0, 123));
}

TEST(Monom, cant_create_monom_with_degree_greater_than_nine)
{
	ASSERT_ANY_THROW(Monom m(1.0, 2312));
}
