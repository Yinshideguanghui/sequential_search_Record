#include"list_simply_linked_no_remembering.h"
#include"list_simply_linked_no_remembering.cpp"

class Key
{
public:
	Key() {}
	Key(string Name) :name_(Name) {}
	bool operator == (Key& k) { return name_ == k.name_; }
protected:
	string name_;
};
class Record
{
public:
	Record() {}
	Record(string Name, string Phone_Num = "000-00") :name(Name), phone_num(Phone_Num) {}
	operator Key() const
	{
		Key k(name);
		return k;
	}
	string retrieve_name() { return name; }
	string retrieve_phone_num() { return phone_num; }
protected:
	string name;
	string phone_num;
};

Error_code sequential_search(const List<Record>& the_list, const Key& target, int& position)
{
	int s = the_list.size();
	for (position = 0; position < s; position++)
	{
		Record data;
		the_list.retrieve(position, data);
		Key temp_key1(data);
		Key temp_key2 = target;
		if (temp_key1 == temp_key2)return success;
	}
	return not_present;
}

void sequential_search_print(const List<Record>& the_list, const Key& target)
{
	int position;
	if (sequential_search(the_list, target, position) == success)
		cout << "position is " << position << endl;
	else
		cout << "not found" << endl;
}

int main()
{
	List<Record> cardinfo;
	Record record1("robert", "970-01"),
		record2("helen", "970-02"),
		record3("mellisa", "970-03");
	cardinfo.insert(0, record1);
	cardinfo.insert(1, record2);
	cardinfo.insert(2, record3);
	string str1 = "robert";
	Key k1(str1);
	Key k2("richard");
	sequential_search_print(cardinfo, k1);
	sequential_search_print(cardinfo, k2);
	return 0;
}