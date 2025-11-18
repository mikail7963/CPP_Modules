#include "PmergeMe.hpp"

PmergeMe::PmergeMe()  {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	this->DequeNum = obj.DequeNum;
	this->VectorNum = obj.VectorNum;
    this->ElementSize = 0;
    this->DequeTime = 0;
    this->VectorTime = 0;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if (this != &obj)
	{
		this->DequeNum = obj.DequeNum;
		this->VectorNum = obj.VectorNum;
        this->ElementSize = obj.ElementSize;
        this->DequeTime = obj.DequeTime;
        this->VectorTime = obj.VectorTime;
	}
	return (*this);
}

void	PmergeMe::AddNumbers(std::string &arg)
{
	int i = 0;
	int len = arg.length();
	int value;
	std::stringstream ss;

	while (i < len)
	{
		if (arg[i] == ' ')
		{
			i++;
			continue;
		}
		ss.clear();
		ss.str("");
		while (arg[i] && arg[i] != ' ')
		{
			ss << arg[i];
			i++;
		}
		ss >> value;
		this->VectorNum.push_back(value);
		this->DequeNum.push_back(value);
		i++;
	}
}

std::vector<int> PmergeMe::fordJohnsonSortVec(std::vector<int> array)
{
    std::vector<std::pair<int, int> > duoList;
    int straggler = 0;
    bool hasStraggler = false;

    if (array.size() <= 1)
        return (array);
    if (array.size() == 2)
    {
        if (array[0] > array[1])
            std::swap(array[0], array[1]);
        return (array);
    }    
    for (size_t i = 0; i + 1 < array.size(); i += 2)
        duoList.push_back(std::make_pair(array[i], array[i + 1]));
    if (array.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = array.back();
    }
    
    for (size_t i = 0;  i < duoList.size() ; ++i)
    {
        if (duoList[i].first > duoList[i].second)
            std::swap(duoList[i].first, duoList[i].second);
    }
    
    std::vector<int> mainChain;
    std::vector<int> pending;
    
    for (size_t i = 0; i < duoList.size(); i++)
        mainChain.push_back(duoList[i].second);

    mainChain = fordJohnsonSortVec(mainChain);
    
    for (size_t i = 0; i < duoList.size(); i++)
        pending.push_back(duoList[i].first);

    std::vector<int> result = mainChain;
        
    if (!duoList.empty())
        result.insert(result.begin(), duoList[0].first);

    std::vector<int>::iterator firstPos;
    std::vector<int>::iterator stragglePos;
    for (size_t i = 1; i < duoList.size(); ++i)
    {
        firstPos = std::lower_bound(result.begin(), result.end(), duoList[i].first);
        result.insert(firstPos, duoList[i].first);
    }
    
    if (hasStraggler)
    {
        stragglePos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(stragglePos, straggler);
    }
    return (result);
}

double PmergeMe::getVectorTime()
{
    return VectorTime;
}

double PmergeMe::getDequeTime()
{
    return DequeTime;
}

void PmergeMe::shortVector()
{
    this->ElementSize = this->VectorNum.size();
	clock_t start = clock();
	this->VectorNum = fordJohnsonSortVec(this->VectorNum);
	clock_t end = clock();
    this->VectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::printVector()
{
	for (size_t i = 0; i < VectorNum.size(); i++)
	{
		std::cout << VectorNum[i] << " ";
	}
	std::cout << std::endl;
	
}

std::deque<int> PmergeMe::fordJohnsonSortDeq(std::deque<int> array)
{
    std::deque<std::pair<int, int> > duoList;
    int straggler = 0;
    bool hasStraggler = false;
    if (array.size() <= 1)
        return array;
    if (array.size() == 2)
    {
        if (array[0] > array[1])
            std::swap(array[0], array[1]);
        return array;
    }
    
    for (size_t i = 0; i + 1 < array.size(); i += 2)
    {
        duoList.push_back(std::make_pair(array[i], array[i + 1]));
    }
    if (array.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = array.back();
    }
    
    for (size_t i = 0;  i < duoList.size() ; ++i)
    {
        if (duoList[i].first > duoList[i].second)
            std::swap(duoList[i].first, duoList[i].second);
    }
    
    std::deque<int> mainChain;
    std::deque<int> pending;
    
    for (size_t i = 0; i < duoList.size(); i++)
        mainChain.push_back(duoList[i].second);

    mainChain = fordJohnsonSortDeq(mainChain);
    
    for (size_t i = 0; i < duoList.size(); i++)
        pending.push_back(duoList[i].first);

    std::deque<int> result = mainChain;
    
    if (!duoList.empty())
        result.insert(result.begin(), duoList[0].first);
    std::deque<int>::iterator firstPos;
    std::deque<int>::iterator stragglePos;
    for (size_t i = 1; i < duoList.size(); ++i)
    {
        firstPos = std::lower_bound(result.begin(), result.end(), duoList[i].first);
        result.insert(firstPos, duoList[i].first);
    }
    if (hasStraggler)
    {
        stragglePos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(stragglePos, straggler);
    }
    return (result);
}

void PmergeMe::shortDeque()
{
	clock_t start = clock();

	this->DequeNum = fordJohnsonSortDeq(this->DequeNum);

	clock_t end = clock();

    this->DequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

}
