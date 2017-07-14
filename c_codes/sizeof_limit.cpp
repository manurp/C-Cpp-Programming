#include<iostream>
#include<limits>

int main()
{
	std::cout<<"size of long"<<sizeof(1L)<<"\n";
	std::cout<<"size of long long"<<sizeof(1ll)<<"\n";

	std::cout<<"largest float=="<<std::numeric_limits<float>::max()<<"\n";
	std::cout<<"char is signed=="<<std::numeric_limits<char>::is_signed<<"\n";
}
