/**
Rohan Suri 
HW 2
This is a program that implements a counter class using the newly learned template 
class that allows us to use all different types(string ints pointers vectors etc) in 
the implementation of a map from keys to values. Our keys are defined by template class
T and our values are ints. Keys are objects and values are counts. For example, if there 
is a vector {"dog", "dog", "dog"}, our "dog" keys object count(value) would be 3. This whole
class implements a variety of functions for this purpose making a map that can add, remove,
increment, decrement, normalize etc. 
This can be ran using 'make' in the commandline which activates usage of our makefile and runs
our main.cpp, test.cpp and counter.hpp
Have fun!
*/
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include "Counter.hpp"
#include <iostream>
using namespace std;


TEST_CASE("Count", "[Count]")
{
	SECTION("Find Count (String Type) No args")
	{
		std::vector<string> v = {"John", "John", "Bob", "Larry"};
		Counter<string> names(v);
		REQUIRE(names.Count()== 4);

	}
	SECTION("Find Count(Int Type) No args)")
	{
		std::vector<int> v = {1,1,1,1,2,2,3,4};
		Counter<int> nums(v);
		REQUIRE(nums.Count()== 8);
	}
	SECTION("Find Count(String Type) 1 argument object T(string)")
	{
		std::vector<string> v = {"John", "John", "Bob", "Larry"};
		Counter<string> names(v);
		REQUIRE(names.Count("John")== 2);
	}
	SECTION("Find Count(Int Type) 1 argument object T(int)")
	{
		std::vector<int> v = {1,1,1,1,2,2,3,4};
		Counter<int> nums(v);
		REQUIRE(nums.Count(1)== 4);
	}
	SECTION("Find Count(String Type) 2 argument T min and T max")
	{
		std::vector<string> v = {"John", "John", "Bob", "Larry"};
		Counter<string> names(v);
		REQUIRE(names.Count("John","Larry")== 2);
	}
	
	SECTION("Find Count(Int Type) 2 argument T min and T max")
	{
		std::vector<int> v = {1,2,3,4};
		Counter<int> nums(v);
		REQUIRE(nums.Count(1,4)== 3);
	}

}

TEST_CASE("Remove", "[Remove]")
{
	SECTION("Remove element (String Type)")
	{
		std::vector<string> v = {"John", "John", "Bob", "Larry"};
		std::vector<string> v2 = {"Bob", "Larry"};
		Counter<string> names(v);
		names.Remove("John");	
		REQUIRE(names.Count("John") == 0);
	}
	SECTION("Remove element (Int Type)")
	{
		std::vector<int> v = {1,1,1,2,3,4};
		std::vector<int> v2 = {2,3,4};
		Counter<int> nums(v);
		nums.Remove(1);	
		REQUIRE(nums.Count() == 3);//Using other count function to avoid sigabrt when comparing 0==0
		//when using nums.Count(1)==0;
	} 

}

TEST_CASE("Increment", "[Increment]")
{
	SECTION("Increment(String Type)")
	{
		std::vector<string> v = {"John", "John", "Bob", "Larry"};
		Counter<string> names(v);
		std::string a = "John";
		names.Increment(a,2);
		REQUIRE(names.Count("John")== 4);
	}
	SECTION("Increment(Int Type)")
	{
		std::vector<int> v = {1,1,1,1,2,2,3,4};
		Counter<int> nums(v);
		int a = 1;
		nums.Increment(a,2);
		REQUIRE(nums.Count(1)== 6);
	}

}

TEST_CASE("Decrement" ,"[Decrement]")
{
	SECTION("Decrement (String Type) 2 args key and n (decrements by n)")
	{
		std::vector<string> v = {"John", "John", "Bob", "Larry"};
		Counter<string> names(v);
		std::string a = "John";
		names.Decrement(a,1);
		REQUIRE(names.Count("John")== 1);
	}
	SECTION("Decrement (Int Type) 2 args key and n (decrements by n)")
	{
		std::vector<int> v = {1,1,1,2,2,3,4,5};
		Counter<int> names(v);
		names.Decrement(1,2);
		REQUIRE(names.Count(1)== 1);
	}
	SECTION("Decrement (String Type) 1 arg T key (only decrements by 1)")
	{
		std::vector<string> v = {"John", "John", "Bob", "Larry"};
		Counter<string> names(v);
		std::string a = "John";
		names.Decrement(a);
		REQUIRE(names.Count("John")== 1);
	}
	SECTION("Decrement (Int Type) 1 arg T key (only decrements by 1")
	{
		std::vector<int> v = {1,1,1,2,2,3,4,5};
		Counter<int> names(v);
		names.Decrement(1);
		REQUIRE(names.Count(1)== 2);
	}

}
TEST_CASE("Most Common", "[MostCommon]")
{
	SECTION("Most Commonly Occuring Objects (Type Int) 1 argument n most commonly occuring")
	{
		std::vector<int> v = {4,3,2,1};//Assume this is a vector of counts
		std::vector<int> v2 = {4, 3};
		Counter<int> names(v);
		REQUIRE(names.MostCommon(2)==v2);
	}
	SECTION("Most Commonly Occuring Objects (Type String)  1 argument n most commonly occuring")
	{
		std::vector<string> v = {"John","John","John", "Bob","Bob", "Smithson"};//Assume this is a vector of counts
		std::vector<string> v2 = {"John", "Bob"};
		Counter<string> names(v);
		REQUIRE(names.MostCommon(2)==v2);
	}
	SECTION("Most Commonly Occuring Objects (Type Int) No arguments")
	{
		std::vector<string> v = {"John","John", "Bob","Smithson"};//Assume this is a vector of counts
		Counter<string> names(v);
		REQUIRE(names.MostCommon()=="John");
	}
	SECTION("Most Commonly Occuring Objects (Type String) No arguments")
	{
		std::vector<int> v = {4,4,3,2,1};//Assume this is a vector of counts
		std::vector<int> v2 = {4, 3, 2, 1};
		Counter<int> names(v);
		REQUIRE(names.MostCommon()== 4);
	}

}

TEST_CASE("Least Common", "[LeastCommon")
{
	SECTION("Least Commonly Occuring Objects (Type Int) 1 argument n most commonly occuring")
	{
		std::vector<int> v = {4,4,4,4,3,3,3,2,2,1};//Assume this is a vector of counts
		std::vector<int> v2 = {1, 2};
		Counter<int> names(v);
		REQUIRE(names.LeastCommon(2)==v2);
	}
	SECTION("Least Commonly Occuring Objects (Type String)  1 argument n most commonly occuring")
	{
		std::vector<string> v = {"John","John","John", "Bob","Bob", "Smithson"};//Assume this is a vector of counts
		std::vector<string> v2 = {"Smithson", "Bob"};
		Counter<string> names(v);
		REQUIRE(names.LeastCommon(2)==v2);
	}
	SECTION("Least Commonly Occuring Objects (Type Int) No arguments")
	{
		std::vector<string> v = {"John","John","John", "Bob","Bob", "Smithson"};//Assume this is a vector of counts
		Counter<string> names(v);
		REQUIRE(names.LeastCommon()=="Smithson");
	}
	SECTION("Least Commonly Occuring Objects (Type String) No arguments")
	{
		std::vector<int> v = {4,4,4,4,3,3,3,2,2,1};//Assume this is a vector of counts
		Counter<int> names(v);
		REQUIRE(names.LeastCommon()== 1);
	}


}
TEST_CASE("Normalize", "[Normalized]")
{
	SECTION("Normalize (String Type)")
	{
		std::vector<string> v = {"cat","cat","cat","cat","cat","cat","cat","cat","dog","dog","dog","dog","hamster","hamster","eagle","eagle","eagle","eagle","eagle","eagle"};
		Counter<string> names(v);
		map<string,double> m_;
		m_ = names.Normalized();
		REQUIRE(m_.find("cat")->second==0.4);
		REQUIRE(m_.find("dog")->second==0.2);
		REQUIRE(m_.find("hamster")->second==0.1);
		REQUIRE(m_.find("eagle")->second==0.3);
	}
	SECTION("Normalize (Int Type)")
	{
		std::vector<int> v = {1,1,1,1,1,1,1,1,2,2,2,2,3,3,4,4,4,4,4,4};
		Counter<int> names(v);
		map<int,double> m_;
		m_ = names.Normalized();
		REQUIRE(m_.find(1)->second==0.4);
		REQUIRE(m_.find(2)->second==0.2);
		REQUIRE(m_.find(3)->second==0.1);
		REQUIRE(m_.find(4)->second==0.3);
	}
}
TEST_CASE("Keys","[Keys]")
{
	SECTION("Set of Keys (String type)")
	{
		std::vector<string> v= {"rat", "bat", "frog", "dragon"};
		Counter<string> names(v);
		std::set <string> animals;
		animals = names.Keys();
		std::set <string> animals2 = {"rat", "bat", "frog", "dragon"};
		std::set <string> animals3 = {"b", "bsgldt", "fsgnjd", "dsgdnjk"};
		REQUIRE(animals == animals2);
		REQUIRE(animals!=animals3);
	}
	SECTION("Set of Keys (Int type)")
	{
		std::vector<int> v= {4,8,7,9};
		Counter<int> names(v);
		std::set <int> numbers;
		numbers = names.Keys();
		std::set <int> numbers2 = {4,8,7,9};
		std::set <int> numbers3 = {4,2,1,78};
		REQUIRE(numbers == numbers2);
		REQUIRE(numbers!=numbers3);
	}

}

TEST_CASE("Values","[Values]")
{
	SECTION("Vector of values (String Type)")
	{
		std::vector<string> v = {"cat","cat","cat","cat","cat","cat","cat","cat","dog","dog","dog","dog","hamster","hamster","eagle","eagle","eagle","eagle","eagle","eagle"};
		Counter<string> names(v);
		std::vector<int> v2= names.Values();
		REQUIRE(v2[0]==8);
	}
	SECTION("Vector of values (Int Type)")
	{
		std::vector<int> v = {1,1,1,1,1,1,1,1,2,2,2,2,3,3,4,4,4,4,4,4};
		Counter<int> names(v);
		std::vector<int> v2= names.Values();
		REQUIRE(v2[0]==8);
	}
	
}