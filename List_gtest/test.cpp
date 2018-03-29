#include "pch.h"
#include "../Polinom/tlist.h"

TEST(TList, can_create_tlist_object_without_any_throws) {
	ASSERT_NO_THROW(TList<int>());
}

TEST(TList, can_insert_element_in_first_position_in_list) {
	TList<int> tl;
	int element = 10;

	tl.InsertFirst(element);
	EXPECT_EQ(10, tl.GetFirst());
}

TEST(TList, can_insert_element_in_last_position_in_list) {
	TList<int> tl;
	int element = 10;

	tl.InsertLast(element);
	EXPECT_EQ(10, tl.GetLast());
}

TEST(TList, can_insert_element_in_current_position_in_list) {
	TList<int> tl;
	int element = 10;

	tl.InsertCurrent(element);
	EXPECT_EQ(10, tl.GetCurrent());
}

TEST(TList, after_reset_current_element_is_equal_to_first) {
	TList<int> tl;

	tl.InsertFirst(5);
	int element1 = 10;
	
	tl.InsertCurrent(element1);
	tl.Reset();

	int element2 = tl.GetFirst();

	EXPECT_EQ(element1, element2);
}

TEST(TList, gonext_function_change_pointer_to_next_element) {
	TList<int> tl;
	int element = 10;
	tl.InsertFirst(5);
	tl.InsertLast(element);
	tl.GoNext();
	EXPECT_EQ(element, tl.GetCurrent());
}

TEST(TList, after_inserting_in_current_position_current_element_stay_after_new_current) {
	TList<int> tl;
	int element = 10;

	tl.InsertFirst(5);
	tl.InsertCurrent(element);
	tl.InsertCurrent(7);
	tl.GoNext();

	EXPECT_EQ(element, tl.GetCurrent());
}

TEST(TList, element_which_stay_before_current_will_stay_before_new_current_when_insert_in_current_position) {
	TList<int> tl;
	int element = 10;

	tl.InsertFirst(5);
	tl.InsertLast(7);
	tl.GoNext();
	tl.InsertCurrent(element);
	tl.Reset();
	tl.GoNext();

	EXPECT_EQ(element, tl.GetCurrent());
}

TEST(TList, isEnd_return_true_when_current_element_equel_stop_element) {
	TList<int> tl;
	tl.InsertLast(1);
	tl.GoNext();

	EXPECT_EQ(true, tl.IsEnd());
}

TEST(TList, isEnd_return_false_when_current_element_isnt_equel_stop_element) {
	TList<int> tl;
	tl.InsertLast(1);

	EXPECT_EQ(false, tl.IsEnd());
}

TEST(TList, isEmpty_return_true_when_list_is_empty) {
	TList<int> tl;

	EXPECT_EQ(true, tl.IsEmpty());
}

TEST(TList, isEmpty_return_false_when_list_isnt_empty) {
	TList<int> tl;
	tl.InsertCurrent(1);

	EXPECT_EQ(false, tl.IsEmpty());
}

TEST(TList, second_element_will_be_first_after_deleting_first_element) {
	TList<int> tl;
	int element = 10;
	tl.InsertFirst(2);
	tl.InsertLast(5);
	tl.GoNext();
	tl.InsertCurrent(element);
	tl.DelFirst();
	
	EXPECT_EQ(element, tl.GetFirst());
}

TEST(TList, prelast_element_will_be_last_after_deleting_last_element) {
	TList<int> tl;
	int element1 = 10;
	tl.InsertFirst(30);
	tl.InsertLast(element1);
	tl.InsertLast(10);
	tl.DelLast();

	EXPECT_EQ(element1, tl.GetLast());
}

TEST(TList, previous_element_will_be_new_current_after_deleting_current) {
	TList<int> tl;
	int element = 10;

	tl.InsertFirst(element);
	tl.InsertLast(10);
	tl.GoNext();
	tl.InsertCurrent(element);
	tl.DelCurrent();

	EXPECT_EQ(element, tl.GetCurrent());
}

TEST(TList, getCurrent_function_assert_throw_when_we_use_it_for_empty_list) {
	TList<int> tl;
	
	ASSERT_ANY_THROW(tl.GetCurrent());
}

TEST(TList, getFirst_function_assert_throw_when_we_use_it_for_empty_list) {
	TList<int> tl;

	ASSERT_ANY_THROW(tl.GetFirst());
}

TEST(TList, getLast_function_assert_throw_when_we_use_it_for_empty_list) {
	TList<int> tl;

	ASSERT_ANY_THROW(tl.GetLast());
}

TEST(TList, SortInput_insert_element_after_lesser_and_before_greater) {
	TList<int> tl;
	int element = 3;

	tl.InsertCurrent(10);
	tl.InsertCurrent(5);
	tl.InsertCurrent(2);
	tl.SortInput(element);
	tl.Reset();
	tl.GoNext();

	EXPECT_EQ(element, tl.GetCurrent());
}

TEST(TList, after_sorting_least_element_will_be_first) {
	TList<int> tl;

	tl.InsertCurrent(10);
	tl.InsertCurrent(15);
	tl.InsertCurrent(7);
	tl.InsertCurrent(13);
	tl.InsertCurrent(9);
	tl.InsertCurrent(5);

	tl.Sort();

	EXPECT_EQ(5, tl.GetFirst());
}

TEST(TList, after_sorting_greatest_element_will_be_last) {
	TList<int> tl;

	tl.InsertCurrent(10);
	tl.InsertCurrent(15);
	tl.InsertCurrent(7);
	tl.InsertCurrent(13);
	tl.InsertCurrent(9);
	tl.InsertCurrent(5);

	tl.Sort();

	EXPECT_EQ(15, tl.GetLast());
}

TEST(TList, after_sorting_second_smallest_will_be_second) {
	TList<int> tl;

	tl.InsertCurrent(10);
	tl.InsertCurrent(15);
	tl.InsertCurrent(7);
	tl.InsertCurrent(13);
	tl.InsertCurrent(9);
	tl.InsertCurrent(5);

	tl.Sort();
	tl.Reset();
	tl.GoNext();

	EXPECT_EQ(7, tl.GetCurrent());
}





