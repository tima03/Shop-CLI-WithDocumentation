#pragma once
 
namespace STD {

	enum SortName
	{
		Name,
		CompanySeller,
		Description,
		Weight
	};

	extern const char* strSortName[4];

	typedef const char* Str;
	typedef unsigned long int Date;

	class Data {
	public:
		Data();
		~Data();

	protected:
		void GenerateId(int key);
		Date GetId();
		Str GetDateOfCreation();
		void SetCurrentTime();
		void ShowCurrentTime();

	private:
		Date id;
		Str DateOfCreation;

		struct TimeNow
		{
			int Day;
			int Mounth;
			int Year;

			int Hours;
			int Minutes;
			int Seconds;
		} CurTime;

	};
}