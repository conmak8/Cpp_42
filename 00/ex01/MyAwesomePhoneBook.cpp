/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhoneBook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:45:44 by cmakario          #+#    #+#             */
/*   Updated: 2024/12/13 11:24:56 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // Required for input and output operations (std::cin, std::cout, std::endl).
#include <string>   // Required for using the std::string class to manage strings.
#include <iomanip>  // Required for formatting output (e.g., std::setw, std::right).
#include <limits>   // Required for handling input validation (e.g., std::numeric_limits).

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	
public:
	Contact() {} ; // * Constractor
	
	void		setContactInfo()
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstName);
		
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastName);
		
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickName);
		
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);
		
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
	}

	void		displayShortContact(int index) const
	{
		std::cout << std::setw(10) << std:: right << index << "|";
		std::cout << std::setw(10) << std:: right << index << (firstName.length() > 10 ? firstName.substr(0,9) + "." : firstName) << "|";
		std::cout << std::setw(10) << std:: right << index << (lastName.length() > 10 ? lastName.substr(0,9) + "." : lastName) << "|";
		std::cout << std::setw(10) << std:: right << index << (nickName.length() > 10 ? nickName.substr(0,9) + "." : nickName) << "|";
		
	}

	void		displayFullContact() const
	{
		std::cout << "First Name: " << firstName << std::endl;
		std::cout << "Last Name: " << lastName << std::endl;
		std::cout << "Nickame: " << nickName << std::endl;
		std::cout << "Phone Number: " << phoneNumber << std::endl;
		std::cout << "Darkest Secret: " << darkestSecret << std::endl;
	}
};

class PhoneBook
{
private:
	Contact contacts[8];
	int	contactCount;
	int	nextIndex;
public:
	PhoneBook() : contactCount(0), nextIndex(0) {}	// *Constractor

	// Method to add a new contact
	void		addContacts()
	{
		contacts[nextIndex].setContactInfo();

		nextIndex = (nextIndex + 1) % 8;
		if (contactCount < 8)
			contactCount++;
	}
	
	void		displayContacts() const
	{
		std::cout << std::setw(10) << std::right << "Index" << "|"
				  << std::setw(10) << std::right << "First Name" << "|"
				  << std::setw(10) << std::right << "Last Name" << "|"
				  << std::setw(10) << std::right << "Nickname" << std::endl;

		for (int i = 0; i < contactCount; i++)
		{
			contacts[i].displayShortContact(i);
		}
	}

	// Method to search for a contact
	void		searchContact() const
	{
		int	index;

		displayContacts();

		std::cout << "Enter the index of the contact you want to view: ";
		std::cin >> index;

		if (std::cin.fail() || index < 0 || index >= contactCount)
		{
			std::cout << "Invalid index." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}
		
		// Clear input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		contacts[index].displayFullContact();
		
	}
};

int	main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD/SEARCH/EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD")
			phoneBook.addContacts();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
	
}