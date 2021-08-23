#ifndef FILE_MANIP_H
#define FILE_MANIP_H

class FileManip {
	public:
		FileManip();

		int getInput(bool error);
		void printItems(int x);
		void itemGetInput();


	private:
		void listOfItems();
		void addItem();
		void removeItem();
		bool validChoice = false;
		bool showAlert = false;

	protected:
		
};
#endif
