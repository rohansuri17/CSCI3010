#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <set> 
#include <algorithm>

using namespace std;

template <class T>
class Counter 
{
	public:
		Counter();
		Counter(std::vector<T> vals);
		int Count();
		int Count(T key);
		int Count(T min, T max);
		void Remove(T key);
		void Increment(T key);
		void Increment(T key, int n);
		void Decrement(T key);
		void Decrement(T key, int n);
		T MostCommon();
		std::vector<T> MostCommon(int n);
		T LeastCommon();
		std::vector<T> LeastCommon(int n);
		std::map<T, double> Normalized();
		std::set<T> Keys();
		std::vector<int> Values();
		template <typename U>
		friend std::ostream& operator<<(std::ostream& os, const Counter<U> &b);
	private:
		map<T,int> m_;
};
/**
Default Constructor does nothing
*/
template <class T>
Counter<T>::Counter()
{

}
/**
Overloaded Constructor initializes all elements counts to 1 and adds any new ones
*/
template <class T>
Counter<T>::Counter(vector<T> vals) 
{
	for(unsigned int i = 0; i < vals.size(); i++)
	{
		typename std::map<T,int>::iterator it = m_.find(vals[i]);
		if(it != m_.end())
		{
			it->second+=1;//initialize count to 1
		}
		else
		{
			m_.insert(std::pair<T,int>(vals[i],1));//insert new key and value with count 1 for value
		}
	}


}
/**
Return integer with all counts so far
@param None
@return integer of total count so far
*/
template <class T> 
int Counter<T>::Count()
{
	int count = 0;
	for(auto it = m_.begin(); it!= m_.end(); it++)//iterate thru map
	{
		count+=it->second;
	}
	return count;
}
/**
Return integer with all counts with respect to object T key
@param object T from template class T which represents a key in our map
@return integer with all counts with respect to object T key
*/
template <class T>
int Counter<T>::Count(T key)
{
	if(m_.find(key) == m_.end())//if key was not found
	{
		m_.find(key)->second = 0;//set count to 0
	}
	return m_.find(key)->second;

}
/**
Return total counts within range from T min to T max 2 objects of the template class T
@param T min and T max template class T objects
@return total counts within range from T min to T max
*/
template <class T>
int Counter<T>::Count(T min, T max)
{
	int count = 0;
	for(auto it = m_.find(min); it != m_.find(max); it++)
	{
		count+=it->second;
	}
	return count;

}
/**
Return None
@param T key an object from the template class T representing a key from a map
@return None
*/
template <class T>
void Counter<T>::Remove(T key)
{
	if(m_.count(key) == 0)
	{
		return;
	}
	else
	{
		m_.erase(key);//remove element key from map see map::erase documentation 
	}
}
/**
Return None
@param T key an object from the template class T representing a key from a map
@return None
*/
template <class T> 
void Counter<T>::Increment(T key)
{
	auto it = m_.find(key);
    if(it == m_.end())//if element does not exist in map
    {
    	m_.insert(std::pair<T,int>(key,1));
       
    }
    else 
    { 
    	it->second++;//increment by 1
    }

}
/**
Return None
@param T key an object from the template class T representing a key from a map and int n amount to increment our T key objects count
@return None
*/
template<class T>
void Counter<T>::Increment(T key, int n)
{
	auto it = m_.find(key);
    if(it == m_.end())//if element does not exist in map
    {
    	m_.insert(std::pair<T,int>(key,n));
       
    }
    else 
    {
    	it->second+=n;//increment by n
    }	

	
}
/**
Return None
@param T key an object from the template class T representing a key from a map 
@return None
*/
template<class T>
void Counter<T>::Decrement(T key)
{
	auto it = m_.find(key);
    if(it == m_.end())
    {
    	m_.insert(std::pair<T,int>(key,0));
       
    }
    else 
    {
    	it->second--;//decrement by 1
    }
    if(m_.find(key)->second<=0)
    	{
    		m_.erase(key);
    	}

}
/**
Return None
@param T key an object from the template class T representing a key from a map and int n amount to decrement our T key objects count
@return None
*/
template <class T>
void Counter<T>::Decrement(T key, int n)
{	
	auto it = m_.find(key);
    if(it == m_.end())
    {
    	m_.insert(std::pair<T,int>(key,1-n));
    }
    else 
    {
    	it->second-=n;//decrement by n
    }
    if(m_.find(key)->second<=0)// if count less than or equal to 0
    	{
    		m_.erase(key);// remove it from map
    	}
}
/**
Return Template class T object representing the Most Common T object
@param None
@return Template class T object representing the Most Common T object
*/
template <class T>
T Counter<T>::MostCommon()
{
	std::vector<std::pair<int,T>> sorted_;
	for(auto it = m_.begin(); it!= m_.end(); it++)
	{
		sorted_.push_back(std::pair<int,T>(it->second,it->first));
	}
	std::sort(sorted_.begin(),sorted_.end());//sort vector in ascending order
	return sorted_[sorted_.size()-1].second;
}
/**
Return Template class T object of the n(from args) most commonly occuring objects
@param int n representing the number of most commonly occuring T objects we want to return
@return Template class T object of the n(from args) most commonly occuring objects
*/
template <class T>
std::vector<T> Counter<T>::MostCommon(int n)
{
	std::vector<std::pair<int,T>> v;
	std::vector<T> keys;
	for(auto it = m_.begin(); it!=m_.end();it++)
	{
		v.push_back(std::pair<int,T>(it->second,it->first));
	}
	std::sort(v.begin(),v.end());//sort vector in ascending order
	std::reverse(v.begin(),v.end());//reverse makes sort in descending order
	for(int i = 0; i<n;i++)
	{
		keys.push_back(v[i].second);
	}
	return keys;

}
/**
Return Template class T object representing the least common T object
@param None
@return Template class T object representing the least common T object
*/
template <class T>
T Counter<T>::LeastCommon()
{
	std::vector<std::pair<int,T>> sorted_;
	for(auto it = m_.begin(); it!= m_.end(); it++)
	{
		sorted_.push_back(std::pair<int,T>(it->second,it->first));
	}
	std::sort(sorted_.begin(),sorted_.end());
	return sorted_[0].second;

}
/**
Return Template class T object of the n(from args) least commonly occuring objects
@param int n representing the number of least commonly occuring T objects we want to return
@return Template class T object of the n(from args) least commonly occuring objects
*/
template <class T>
std::vector<T> Counter<T>::LeastCommon(int n)
{
	std::vector<std::pair<int,T> > v;
	std::vector<T> keys;
	for(auto it = m_.begin(); it!=m_.end();it++)
	{
		v.push_back(std::pair<int,T>(it->second,it->first));
	}
	std::sort(v.begin(),v.end());
	for(int i = 0; i<n; i++)
	{
		keys.push_back(v[i].second);
	}
	return keys;

}
/**
Return map from template class t object(key) to double object
@param None
@return map of normalized objects based on their counts
*/
template <class T>
std::map<T, double> Counter<T>::Normalized()
{
	double normalized_percent;
	map<T, double> map_;
	for(auto it = m_.begin(); it!=m_.end();it++)
	{
		normalized_percent = ((double) it->second)/((double) Count());
		map_.insert(pair<T,double>(it->first,normalized_percent));
	}
	return map_;

}
/**
Return set of Keys of type template class T object representing keys in map
@param None
@return set of Keys of type template class T object representing keys in map
*/
template <class T>
std::set<T> Counter<T>::Keys()
{
	std::set<T> key;
	for(auto it = m_.begin(); it != m_.end(); it++)
	{
		key.insert(it->first);
	}
	return key;

}
/**
Return vector of Values of type template class T object representing values in Map
@param None
@return vector of Values of type template class T object representing values in Map
*/
template <class T>
std::vector<int> Counter<T>::Values()
{
	std::vector<int> values;
	for(auto it = m_.begin(); it != m_.end(); it++)
	{
		values.push_back(it->second);
	}
	return values;
}
template <class U>
std::ostream& operator<<(std::ostream& os, const Counter<U> &b)
{
	os<<"{";
	for(auto it = b.m_.begin(); it != b.m_.end();it++)
	{
		os<<it->first<< ":"<< it->second<<",";
	}
	os<<"}\n";
	return os;

}
