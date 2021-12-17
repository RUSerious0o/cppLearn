#pragma once

using namespace std;

template <typename value_type>
class CustomIterator : public std::iterator<std::forward_iterator_tag, value_type> {
	friend class CustomContainer;
public:
	CustomIterator(value_type* p) : p(p) {}
	CustomIterator(const CustomIterator& it) : p(it.p) {}

	bool operator!=(CustomIterator const& other) {
		return p != other.p;
	}

	bool operator==(CustomIterator const& other) {
		return p == other.p;
	}

	typename CustomIterator<value_type>::reference operator*() {
		return *p;
	}

	CustomIterator<value_type>& operator++() {
		++p;
		return*this;
	}
private:
	value_type* p;
};

class CustomContainer {
	typedef CustomIterator<int> iterator;
	typedef CustomIterator<const int> const_iterator;

public:
	CustomContainer(initializer_list<int> values) :
		size(values.size()), data(new int[size]) 	{
		std::copy(values.begin(), values.end(), data.get());
	}

	iterator begin() {
		return iterator(data.get());
	}

	iterator end() {
		return iterator(data.get() + size);
	}

	const_iterator begin() const {
		return const_iterator(data.get());
	}

	const_iterator end() const {
		return const_iterator(data.get() + size);
	}

private:
	size_t size;
	unique_ptr<int[]> data;
};