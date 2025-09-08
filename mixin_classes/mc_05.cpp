#include <iostream>
#include <type_traits>

template <typename Base>
class SkillA : public Base {};

template <typename Base>
class SkillB : public Base {};

template <typename Base>
class SkillC : public Base {};

class Nec {};


int main()
{
	using t1 = SkillA<SkillB<SkillC<Nec>>>;  //ABC
	using t2 = SkillA<SkillC<SkillB<Nec>>>;  //ACB
	using t3 = SkillB<SkillA<SkillC<Nec>>>;  //BAC
	using t4 = SkillB<SkillC<SkillA<Nec>>>;  //BCA
	using t5 = SkillC<SkillA<SkillB<Nec>>>;  //CAB
	using t6 = SkillC<SkillB<SkillA<Nec>>>;  //CBA

	static_assert(!std::is_same_v<t1, t2> &&
		!std::is_same_v<t1, t3> &&
		!std::is_same_v<t1, t4> &&
		!std::is_same_v<t1, t5> &&
		!std::is_same_v<t1, t6>); //holds
}
