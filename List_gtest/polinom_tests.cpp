#include "pch.h"
#include "../Polinom/TPolinom.h"
#include "../Polinom/TPolinom.cpp"

TEST(TPolinom, can_create_object_of_polinom_class_without_any_throw) {
	ASSERT_NO_THROW(TPolinom());
}

TEST(TPolinom, can_create_and_init_object_of_polinom_class_without_any_throw) {
	TMonom tm[] = {
		{1, 1, 1, 1},
		{2, 0, 1, 2},
		{3, 0, 0, 1}
	};
	TMonom *tmp = tm;

	ASSERT_NO_THROW(TPolinom(tmp, 3));
}

TEST(TPolinom, can_create_polinom_object_by_coping_other_object_of_this_class) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 1 }
	};
	TMonom *tmp = tm1;
	
	TPolinom tp1(tmp, 3);

	ASSERT_NO_THROW(TPolinom(tp1));
}

TEST(TPolinom, can_clear_tpolinom) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 1 }
	};
	TMonom *tmp = tm1;

	TPolinom tp1(tmp, 3);
	tp1.ClearTPolinom();
	
	EXPECT_TRUE(tp1.IsEmpty());
}

TEST(TPolinom, can_assign_two_object_of_class_polinom_without_any_throw) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 1 }
	};
	TMonom *tmp = tm1;

	TPolinom tp1(tmp, 3);
	TPolinom tp2;

	ASSERT_NO_THROW(tp2 = tp1);
}

TEST(TPolinom, assigned_objects_are_equal) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 1 }
	};
	TMonom *tmp = tm1;

	TPolinom tp1(tmp, 3);
	TPolinom tp2;

	tp2 = tp1;

	EXPECT_EQ(tp1, tp2);
}

TEST(TPolinom, after_insertingByOrder_function_element_which_is_less_than_inserted_stay_after_inserted) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 1 }
	};
	TMonom *tmp = tm1;

	TPolinom tp1(tmp, 3);
	TMonom tm2 = { 2, 1, 0, 0 };
	TMonom tm3 = { 2, 0, 1, 2 };

	tp1.InsertByOrder(tm2);
	tp1.Reset();
	tp1.GoNext();
	//tp1.GoNext();

	EXPECT_EQ(tp1.GetCurrent(), tm2);
}

TEST(TPolinom, after_insertingByOrder_function_element_which_is_more_than_inserted_stay_before_inserted) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 1 }
	};
	TMonom *tmp = tm1;

	TPolinom tp1(tmp, 3);
	TMonom tm2 = { 2, 1, 0, 0 };
	TMonom tm3 = { 1, 1, 1, 1};
	TMonom expectedMonom;
	
	tp1.InsertByOrder(tm2);
	tp1.Reset();
	expectedMonom = tp1.GetCurrent();
	
	EXPECT_EQ(expectedMonom, tm3);
	
	tp1.GoNext();

	EXPECT_EQ(tp1.GetCurrent(), tm2);
}

TEST(TPolinom, multyplication_on_constant_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 1 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom expected[] = {
		{3, 1, 1, 1},
		{6, 0, 1, 2},
		{9, 0, 0, 1}
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 3);

	const int c = 3;

	EXPECT_EQ(tp1 * 3, expectedPoli);
}

TEST(TPolinom, multyplication_on_monom_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 1 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom expected[] = {
		{ 3, 3, 1, 2 },
		{ 6, 2, 1, 3 },
		{ 9, 2, 0, 2 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 3);

	TMonom multiplier = { 3, 2, 0, 1 };

	EXPECT_EQ(tp1 * multiplier, expectedPoli);
}

TEST(TPolinom, addition_of_two_polinoms_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2[] = {
		{ 4, 1, 1, 1 },
		{ 1, 0, 1, 3 },
		{ 5, 0, 0, 1 }
	};
	TMonom *tmp2 = tm2;
	TPolinom tp2(tmp2, 3);

	TMonom expected[] = {
		{ 5, 1, 1, 1 },
		{ 1, 0, 1, 3 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 },
		{ 5, 0, 0, 1 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 5);

	EXPECT_EQ(tp1 + tp2, expectedPoli);
}

TEST(TPolinom, difference_of_two_polinoms_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2[] = {
		{ 4, 1, 1, 1 },
		{ 1, 0, 1, 3 },
		{ 5, 0, 0, 1 }
	};
	TMonom *tmp2 = tm2;
	TPolinom tp2(tmp2, 3);

	TMonom expected[] = {
		{ -3, 1, 1, 1 },
		{ -1, 0, 1, 3 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 },
		{ -5, 0, 0, 1 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 5);

	EXPECT_EQ(tp1 - tp2, expectedPoli);
}

TEST(TPolinom, addition_of_polinom_and_monom_which_have_degree_equal_to_one_of_monoms_in_polinom_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2 = { 4, 1, 1, 1 };

	TMonom expected[] = {
		{ 5, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 3);
	TPolinom result = tp1 + tm2;

	EXPECT_EQ(result, expectedPoli);
}

TEST(TPolinom, addition_of_polinom_and_monom_which_have_degree_not_equal_to_any_of_monoms_in_polinom_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2 = { 4, 1, 0, 1 };

	TMonom expected[] = {
		{ 1, 1, 1, 1 },
		{ 4, 1, 0, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 4);

	EXPECT_EQ(tp1 + tm2, expectedPoli);
}

TEST(TPolinom, difference_of_polinom_and_monom_which_have_degree_equal_to_one_of_monoms_in_polinom_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2 = { 4, 1, 1, 1 };

	TMonom expected[] = {
		{ -3, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 3);

	EXPECT_EQ(tp1 - tm2, expectedPoli);
}

TEST(TPolinom, difference_of_polinom_and_monom_which_have_degree_not_equal_to_any_of_monoms_in_polinom_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2 = { 4, 1, 0, 1 };

	TMonom expected[] = {
		{ 1, 1, 1, 1 },
		{ -4, 1, 0, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 4);

	EXPECT_EQ(tp1 - tm2, expectedPoli);
}

//same, but for *=, -=, += operators


TEST(TPolinom, multyplication_with_assign_on_constant_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 1 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom expected[] = {
		{ 3, 1, 1, 1 },
		{ 6, 0, 1, 2 },
		{ 9, 0, 0, 1 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 3);

	const int c = 3;
	tp1 *= 3;

	EXPECT_EQ(tp1, expectedPoli);
}

TEST(TPolinom, multyplication_with_assign_on_monom_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 1 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom expected[] = {
		{ 3, 3, 1, 2 },
		{ 6, 2, 1, 3 },
		{ 9, 2, 0, 2 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 3);

	TMonom multiplier = { 3, 2, 0, 1 };

	tp1 *= multiplier;

	EXPECT_EQ(tp1, expectedPoli);
}

TEST(TPolinom, addition_with_assign_of_two_polinoms_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2[] = {
		{ 4, 1, 1, 1 },
		{ 1, 0, 1, 3 },
		{ 5, 0, 0, 1 }
	};
	TMonom *tmp2 = tm2;
	TPolinom tp2(tmp2, 3);

	TMonom expected[] = {
		{ 5, 1, 1, 1 },
		{ 1, 0, 1, 3 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 },
		{ 5, 0, 0, 1 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 5);

	tp1 += tp2;

	EXPECT_EQ(tp1, expectedPoli);
}

TEST(TPolinom, difference_with_assign_of_two_polinoms_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2[] = {
		{ 4, 1, 1, 1 },
		{ 1, 0, 1, 3 },
		{ 5, 0, 0, 1 }
	};
	TMonom *tmp2 = tm2;
	TPolinom tp2(tmp2, 3);

	TMonom expected[] = {
		{ -3, 1, 1, 1 },
		{ -1, 0, 1, 3 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 },
		{ -5, 0, 0, 1 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 5);

	tp1 -= tp2;

	EXPECT_EQ(tp1, expectedPoli);
}

TEST(TPolinom, addition_with_assign_of_polinom_and_monom_which_have_degree_equal_to_one_of_monoms_in_polinom_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2 = { 4, 1, 1, 1 };

	TMonom expected[] = {
		{ 5, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 3);

	tp1 += tm2;

	EXPECT_EQ(tp1, expectedPoli);
}

TEST(TPolinom, addition_with_assign_of_polinom_and_monom_which_have_degree_not_equal_to_any_of_monoms_in_polinom_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2 = { 4, 1, 0, 1 };

	TMonom expected[] = {
		{ 1, 1, 1, 1 },
		{ 4, 1, 0, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 4);

	tp1 += tm2;

	EXPECT_EQ(tp1, expectedPoli);
}

TEST(TPolinom, difference_with_assign_of_polinom_and_monom_which_have_degree_equal_to_one_of_monoms_in_polinom_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2 = { 4, 1, 1, 1 };

	TMonom expected[] = {
		{ -3, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 3);

	tp1 -= tm2;

	EXPECT_EQ(tp1, expectedPoli);
}

TEST(TPolinom, difference_with_assign_of_polinom_and_monom_which_have_degree_not_equal_to_any_of_monoms_in_polinom_work_correctly) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2 = { 4, 1, 0, 1 };

	TMonom expected[] = {
		{ 1, 1, 1, 1 },
		{ -4, 1, 0, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *pexpected = expected;
	TPolinom expectedPoli(pexpected, 4);

	tp1 -= tm2;

	EXPECT_EQ(tp1, expectedPoli);
}

TEST(TPolinom, equality_ñomparing_of_two_polinoms_return_true_when_polinoms_are_equal) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp1 = tm2;
	TPolinom tp2(tmp1, 3);

	EXPECT_TRUE(tp1 == tp2);
}

TEST(TPolinom, equality_ñomparing_of_two_polinoms_return_false_when_polinoms_have_not_equal_degrees_but_equal_coeffs) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 3 }
	};
	TMonom *tmp1 = tm2;
	TPolinom tp2(tmp1, 3);

	EXPECT_FALSE(tp1 == tp2);
}

TEST(TPolinom, equality_ñomparing_of_two_polinoms_return_false_when_polinoms_have_equal_degrees_but_not_equal_coeffs) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 5, 0, 0, 6 }
	};
	TMonom *tmp1 = tm2;
	TPolinom tp2(tmp1, 3);

	EXPECT_FALSE(tp1 == tp2);
}

TEST(TPolinom, inequality_ñomparing_of_two_polinoms_return_true_when_polinoms_are_equal) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp1 = tm2;
	TPolinom tp2(tmp1, 3);

	EXPECT_FALSE(tp1 != tp2);
}

TEST(TPolinom, inequality_ñomparing_of_two_polinoms_return_true_when_polinoms_have_not_equal_degrees_but_equal_coeffs) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 3 }
	};
	TMonom *tmp1 = tm2;
	TPolinom tp2(tmp1, 3);

	EXPECT_TRUE(tp1 != tp2);
}

TEST(TPolinom, inequality_ñomparing_of_two_polinoms_return_true_when_polinoms_have_equal_degrees_but_not_equal_coeffs) {
	TMonom tm1[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 3, 0, 0, 6 }
	};
	TMonom *tmp = tm1;
	TPolinom tp1(tmp, 3);

	TMonom tm2[] = {
		{ 1, 1, 1, 1 },
		{ 2, 0, 1, 2 },
		{ 5, 0, 0, 6 }
	};
	TMonom *tmp1 = tm2;
	TPolinom tp2(tmp1, 3);

	EXPECT_TRUE(tp1 != tp2);
}

TEST(TPolinom, string_to_monom_function_work_correctly) {
	std::string str = "5yz^6";
	TMonom expectedMonom = { 5, 0, 1, 6 };
	TMonom monom(str);

	EXPECT_EQ(expectedMonom, monom);
}

TEST(TPolinom, from_string_function_work_correctly) {
	TMonom tm1[] = {
		{ 1, 5, 4, 0 },
		{ -4, 3, 4, 7 },
		{ 3, 0, 2, 0 }
	};
	//TMonom *tmp1 = tm1;
	TPolinom p;
	TPolinom expected(tm1, 3);
	std::string str = "x^5y^4 - 4x^3y^4z^7 + 3y^2";
	p.FromString(str);

	EXPECT_EQ( p, expected );
}

TEST(TPolinom, from_string_function_work_correctly_with_string_of_unordered_monoms) {
	TMonom tm1[] = {
		{ 1, 5, 4, 0 },
		{ 4, 3, 4, 7 },
		{ 3, 0, 2, 0 }
	};
	//TMonom *tmp1 = tm1;
	TPolinom p;
	TPolinom expected(tm1, 3);
	std::string str = "4x^3y^4z^7 + 3y^2 + x^5y^4";
	p.FromString(str);

	EXPECT_EQ(p, expected);
}

TEST(TPolinom, can_initialize_from_string_correctly) {
	TMonom tm1[] = {
		{ 1, 5, 4, 0 },
		{ 4, 3, 4, 7 },
		{ 3, 0, 2, 0 }
	};
	//TMonom *tmp1 = tm1;
	std::string str = "x^5y^4 + 4x^3y^4z^7 + 3y^2";
	TPolinom p(str);
	TPolinom expected(tm1, 3);

	EXPECT_EQ(p, expected);
}




