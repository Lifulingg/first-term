#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <time.h>

std::mutex mutex_s;
void peint(int datainit, int threadnum)
{
	for(auto i = 0; i <= 1000;)
	{
		mutex_s.lock();
		sleep(0.08);
		std::cout<< i <<std::endl;
		mutex_s.unlock();

		i  = i +threadnum;
	}



}







int main()
{
	int threadnum = 4;

	std::thread threadarr[threadnum];
	for(auto i =0 ; i <threadnum ; i++)
	{

		threadarr[i] = std::thread(peint, i, threadnum);


	}
	for(int j = 0; j <threadnum; j++)
	{
		threadarr[j].join();
	}


	return 0




}




