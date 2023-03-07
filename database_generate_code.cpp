#include<iostream>
#include<fstream>

using namespace std;

string road_gen()
{
	char road1;
	string road;
	road1 = rand() % 26 + 'A';
	road.push_back(road1);
	for (int l = rand() % 5 + 1; l > 0; l--) {
		road1 = rand() % 26 + 'a';//随机生成少于19个字母组合
		road.push_back(road1);
	}
	
	return road;
}//create address;
string street_gen()
{
	string street;
	char street1;
	street1 = rand() % 26 + 'A';
	street.push_back(street1);
	for (int l = rand() % 5 + 1; l > 0; l--) {
		street1 = rand() % 26 + 'a';//随机生成少于19个字母组合
		street.push_back(street1);
	}
	return street;
}
string name_gen()
{
	char name1;
	string name;

	name1 = rand() % 26 + 'A';
	name.push_back(name1);
	for (int l = rand() %3+6; l > 0; l--) {
		name1 = rand() % 26 + 'a';//生成6-9个字母
		name.push_back(name1);
	}
	return name;
}
string type()
{
	string list[11] = { "Bentonite","tofu","pine","crystal","mixed","confetti","zeolite","hay","corn_cob","activated","grain"};
	int num = rand() % 11;
	return list[num];
}

string smell()
{
	string list[7] = { "Green_tea","cherry_blossom","peach","unscented","pine","milk","mint" };
	int num = rand() % 7;
	return list[num];
}
string daily_necessities_efficacy()
{
	string list[5] = { "Hair cream","lecithin","probiotics","catnip","dewormer" };
	int num = rand() % 5;
	return list[num];
}

string health_care_efficacy()
{
	string list[8] = { "Oral_hygiene","anti_inflammatory","cleaning","health_care","deworming","hair_care","disinfection","nutritional_product" };
	int num = rand() % 8;
	return list[num];
}
string textture()
{
	string list[9] = { "Paper_products","chemical_fiber","plastic","cotton","resin","metal","silicone","wood_bamboo","water_paint"};
	int num = rand() % 9;
	return list[num];
}
int weight()
{
	int num = rand() % 1000 + 10;
	return num;
}
string ingredient()
{
	string list[9] = {"Chicken breast","eggs","salmon","fruits","dairy_products"," fats_oils","broccoli","soy_products","beef" };
	int num = rand() % 9;
	return list[num];
}
string brand()
{
	string list[17] = {"Royal","Bernard Pure","Crazy Puppy","Jenzy","McFaddie","Wanpy","SOLID GOLD","Pedigree","Origen","Nutro","K9","Tianhengbao","Lingcai","Hill's","PURINA","MISTER"};
	int num = rand() % 9;
	return list[num];
}
int main()
{

	string road;
	string street;
	string name;
	char c;
	//customer table
	fstream data_gen("data_generation.sql", 'w');
	data_gen << "INSERT INTO customer VALUES" << endl;
	
	for (int i = 0; i < 50000+1; i++)
	{
		data_gen << "(";
	
		int id_num = 100000+i;
		data_gen <<"'"<<"c"<<id_num<<"',"; //customer生成用c开头的id

		name = name_gen();
		data_gen <<"'" << name <<"'" << ",";//name
		int num = 0;
		num = (rand() % 900000) + 100000;//随机生成10000-100000的随机数
		data_gen << num << ",";//password;

		data_gen << "'" << "road:" << road_gen() << " " << "street:" << street_gen() << "'" << ",";//create address
		data_gen << 20000 + i ;//credict_card_id 2开头
		if (i < 50000)
		{
			data_gen << ")" <<"," << endl;
		}
		else if (i == 50000)
		{
			data_gen << ")" << ";" << endl;
		}

	}
	//manager table
	data_gen << endl;

	data_gen << "INSERT INTO manager VALUES" << endl;

	for (int i = 0; i < 10000+1; i++)
	{

		data_gen << "(";

		int id_num = 100000+i;
		data_gen <<"'"<<"m"<<id_num<<"',"; //manager 生成用m开头的id

		name = name_gen();
		data_gen << "'" << name << "'" << ",";//name
		int num = 0;
		num = (rand() % 900000) + 100000;//随机生成10000-100000的随机数
		data_gen << num ;//password;
		if (i < 10000)
		{
			data_gen << ")" << "," << endl;
		}
		else if (i == 10000)
		{
			data_gen << ")" << ";" << endl;
		}

	}
	//owner table
	data_gen << endl;

	data_gen << "INSERT INTO owner VALUES" << endl;

	for (int i = 0; i < 50000+1; i++)
	{
		data_gen << "(";

		int id_num = 100000 + i;
		data_gen << "'" << "o" << id_num << "',"; //owner 生成用o开头的id

		name = name_gen();
		data_gen << "'" << name << "'" << ",";//name
		int num = 0;
		num = (rand() % 900000) + 100000;//随机生成10000-100000的随机数
		data_gen << num <<",";//password;

		//create address
	
		data_gen << "'" << "road:" << road_gen() << " " << "street:" << street_gen() << "'" ;//create address

		if (i < 50000)
		{
			data_gen << ")" << "," << endl;
		}
		else if (i == 50000)
		{
			data_gen << ")" << ";" << endl;
		}


	}
	//supplier table
	data_gen << endl;
	data_gen << "INSERT INTO supplier VALUES" << endl;

	for (int i = 0; i < 10000+1; i++)
	{

		string legal_person_name;
		data_gen << "(";

		int id_num = 100000 + i;
		data_gen << "'" << "s" << id_num << "',"; //supplier 生成用s开头的id

		
		data_gen << "'" << name_gen() << "'" << ",";//create name

		data_gen <<"'"<<"road:" << road_gen() << " " << "street:" << street_gen() << "'" << ",";//create address


	
		data_gen << "'" << name_gen() << "'";
		if (i < 10000)
		{
			data_gen << ")" <<"," << endl;
		}
		else if (i == 10000)
		{
			data_gen << ")" << ";" << endl;
		}

	}
	//product_table

	//cat_litter
	data_gen << "INSERT INTO cat_litter VALUES" << endl;

	for (int i = 0; i <10000+1; i++)
	{
		double price;
		string weight;
		char c;
		data_gen << "(";

		int id_num = 100000 + i;
		data_gen << "'" << "c_l" << id_num << "',"; //supplier 生成用s开头的id

		
		data_gen <<"'" << name_gen() << "'" << ",";//name
		price = (double)(rand() % 11) / 10;
		price = double( price + rand() % 1000);
		data_gen << price << ",";//price
		c = rand() % 26 + 'A';//随机生成首字母
		
		//需要重新写一个smell \weight.

		
		data_gen << "'" << type() << "'" << ",";
		data_gen << "'" << smell() << "'" << ",";
		int weight1 = rand() % 990 +10;
		data_gen << "'" << weight1 <<"g" << "'";
		if (i < 10000)
		{
			data_gen << ")" << "," << endl;
		}
		else if (i == 10000)
		{
			data_gen << ")" << ";" << endl;
		}
		

	}
	//daily-necessities
	data_gen << "INSERT INTO daily_necessities VALUES" << endl;
	
	for (int i = 0; i < 10000 + 1; i++)
	{
		double price;
		string type;
		string weight;
		char c;
		data_gen << "(";

		int id_num = 100000 + i;
		data_gen << "'" << "d_n" << id_num << "',"; //supplier 生成用s开头的id


		data_gen << "'" << name_gen() << "'" << ",";//name
		price = (double)(rand() % 11) / 10;
		price = double(price + rand() % 330+20);
		data_gen << price << ",";//price
		data_gen <<"'" << daily_necessities_efficacy() <<"'";//efficacy

		if (i < 10000)
		{
			data_gen << ")" << "," << endl;
		}
		else if (i == 10000)
		{
			data_gen << ")" << ";" << endl;
		}


	}

	//health_care
	data_gen << "INSERT INTO health_care VALUES" << endl;

	for (int i = 0; i < 10000 + 1; i++)
	{
		double price;
		string type;
		string weight;
		char c;
		data_gen << "(";

		int id_num = 100000 + i;
		data_gen << "'" << "h_c" << id_num << "',"; 


		data_gen << "'" << name_gen() << "'" << ",";//name
		price = (double)(rand() % 11) / 10;
		price = double(price + rand() % 330 + 20);
		data_gen << price << ",";//price
		data_gen << "'" << health_care_efficacy() << "',";//efficacy

		int num = rand() % 2 +2023;
		data_gen << "'" << num << "-";
		num = rand() % 12+1;
		data_gen << num << "-";
		num = rand() % 30+1;
		data_gen << num << "'";//establish_time;

		if (i < 10000)
		{
			data_gen << ")" << "," << endl;
		}
		else if (i == 10000)
		{
			data_gen << ")" << ";" << endl;
		}


	}
	//toy
	data_gen << "INSERT INTO toy VALUES" << endl;

	for (int i = 0; i < 10000 + 1; i++)
	{
		double price;
		data_gen << "(";

		int id_num = 100000 + i;
		data_gen << "'" << "toy" << id_num << "',"; //supplier 生成用s开头的id

		data_gen << "'" << name_gen() << "'" << ",";//name

		price = (double)(rand() % 11) / 10;
		price = double(price + rand() % 200 + 20);
		data_gen << price << ",";//price
		data_gen << "'" << textture() << "',";//efficacy
		data_gen << "'" << weight() << "g'";
		if (i < 10000)
		{
			data_gen << ")" << "," << endl;

		}
		else if (i == 10000)
		{
			data_gen << ")" << ";" << endl;
		}


}
//pet_food

	data_gen << "INSERT INTO pet_food VALUES" << endl;

	for (int i = 0; i < 10000 + 1; i++)
	{
		double price;
		data_gen << "(";

		int id_num = 100000 + i;
		data_gen << "'" << "pf" << id_num << "',"; //supplier 生成用s开头的id

		data_gen << "'" << name_gen() << "'" << ",";//name

		price = (double)(rand() % 11) / 10;
		price = double(price + rand() % 500 + 100);
		data_gen << price << ",";//price

		data_gen << "'" << ingredient() << "',";//efficacy
		data_gen << "'" << brand() << "'";
		if (i < 10000)
		{
			data_gen << ")" << "," << endl;

		}
		else if (i == 10000)
		{
			data_gen << ")" << ";" << endl;
		}
	}
	//store table
	data_gen << endl;
		data_gen << "INSERT INTO store VALUES" << endl;

		for (int i = 0; i < 10000 +1; i++)
		{
			string est_time;//establish_time
			data_gen << "(";            
			
			int id_num = 110000 + i;//store 的数据范围为11万到12万；
			//int id_num = 100000 + i;
			data_gen << "'" << "s_t" << id_num << "',"; //store生成用s_t开头的id

			int num = rand() % 122 + 1900;
			data_gen << "'" << num << "-";
			num = rand() % 12+1;
			data_gen << num << "-";
			num = rand() % 30+1;
			data_gen << num << "',";//establish_time;

			data_gen << "'" << "road:" << road_gen() << " " << "street:" << street_gen() << "',";//create address
				

			data_gen << "'" << name_gen() << "',";//legal_person

			num = rand() % 10000 + 100000;
			data_gen << "'o" << num << "'";//生成只有1-100的owner_id；

			if (i < 10000)
			{
				data_gen << ")" <<"," << endl;
			}
			else if (i == 10000)
			{
				data_gen << ")" << ";" << endl;
			}
			

		}
	
	//consistent

	data_gen << "INSERT INTO consist VALUES" << endl;
	for (int i = 0; i < 10000 + 1; i++)
	{
		data_gen << "(";

		int id_num = 10000 + i;
		data_gen << "'" << "2022000" << id_num << "',"; //store生成用s_t开头的id

		if (i <= 2000)
		{
			data_gen << "'" << "c_l" << 100000 + rand() % 10000 << "'"; //supplier 生成用s开头的id
		}
		if ((i > 2000) && (i <= 4000))
		{
			data_gen << "'" << "d_n" << 100000 + rand() % 10000 << "'"; //supplier 生成用s开头的id
		}
		if ((i > 4000) && (i <=6000))
		{
			data_gen << "'" << "h_c" << 100000 + rand() % 10000 << "'"; //supplier 生成用s开头的id
		}
		if ((i > 6000) && (i <= 8000))
		{
			data_gen << "'" << "toy" << 100000 + rand() % 10000 << "'"; //supplier 生成用s开头的id
		}
		if (i > 8000 && i <= 10000)
		{
			data_gen << "'" << "pf" << 100000 + rand() % 10000 << "'"; //supplier 生成用s开头的id
		}
		
		if (i < 10000)
		{
			data_gen << ")" << "," << endl;

		}
		if (i == 10000)
		{
			data_gen << ")" << ";" << endl;
		}
	}

	data_gen << endl;

	//inventory
	data_gen << "INSERT INTO inventory VALUES" << endl;
	for (int i = 0; i < 10000 + 1; i++)
	{
		data_gen << "(";


		if (i <=2000)
		{
			data_gen << "'" << "c_l" << 100000 + rand() % 10000 << "',";
		}
		if (i > 2000 && i <= 4000)
		{
			data_gen << "'" << "d_n" << 100000 + rand() % 10000 << "',";
		}
		if (i > 4000 && i <= 6000)
		{
			data_gen << "'" << "h_c" << 100000 + rand() % 10000 << "',";
		}
		if (i > 6000 && i <= 8000)
		{
			data_gen << "'" << "toy" << 100000 + rand() % 10000 << "',";
		}
		if (i > 8000 && i <= 10000)
		{
			data_gen << "'" << "pf" << 100000 + rand() % 10000 << "',";
		}
		

		data_gen << "'" << "s_t" << 100000+rand()%10000+10000 << "',";
		data_gen << rand() % 8999 + 1000 ;

		if (i < 10000)
		{
			data_gen << ")" << "," << endl;
		}
		else if (i == 10000)
		{
			data_gen << ")" << ";" << endl;
		}

	}
	
	data_gen << endl;

	//order_list
	data_gen << "INSERT INTO order_list VALUES" << endl;
	for (int i = 0; i < 10000 + 1; i++)
	{
		data_gen << "(";

		int id_num = 10000 + i;
		data_gen << "'" << "2022000" << id_num << "',"; //store生成用s_t开头的id
		data_gen << "'" << "c" <<100000+rand()%40000+10000<<"',";
		data_gen << "'" << "m" << 100000+rand()%10000 << "'";
		if (i < 10000)
		{
			data_gen << ")" << "," << endl;
		}
		else if (i == 10000)
		{
			data_gen << ")" << ";" << endl;
		}
	}

	data_gen << endl;

	//supply
	data_gen << "INSERT INTO supply VALUES" << endl;
	for (int i = 0; i < 10000 + 1; i++)
	{
		data_gen << "(";

		data_gen << "'" << "s" << rand() % 10000 + 100000 << "',";


		if (i <= 2000)
		{
			data_gen << "'" << "c_l" << 100000 + rand() % 10000 << "'";
		}
		if (i > 2000 && i <= 4000)
		{
			data_gen << "'" << "d_n" << 100000 + rand() % 10000 << "'";
		}
		if (i > 4000 && i <= 6000)
		{
			data_gen << "'" << "h_c" << 100000 + rand() % 10000 << "'";
		}
		if (i > 6000 && i <= 8000)
		{
			data_gen << "'" << "toy" << 100000 + rand() % 10000 << "'";
		}
		if (i > 8000 && i <= 10000)
		{
			data_gen << "'" << "pf" << 100000 + rand() % 10000 << "'";
		}

		if (i < 10000)
		{
			data_gen << ")" << "," << endl;
		}
		else if (i == 10000)
		{
			data_gen << ")" << ";" << endl;
		}
	}
	return 0;
	
}