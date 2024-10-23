/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:40:12 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/23 22:06:36 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.hpp"
#include "./Data.hpp"

int	main() {
	Data originalData;
	originalData.id = 42;
	originalData.name = "Test Data";
	originalData.value = 3.14f;

	// Serialize the Data object
	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << raw << std::endl;
	// Deserialize the raw value back to a Data pointer
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << deserializedData->id << std::endl;
	std::cout << &originalData.id << std::endl;
	std::cout << &originalData.name << std::endl;
	std::cout << &originalData.value << std::endl;
	
	// Ensure the deserialized pointer copmares equal to the original pointer
	if (deserializedData == &originalData) {
		std::cout << "Serialization and deserialization successful!" << std::endl;
		std::cout << "ID: " << deserializedData->id << std::endl;
		std::cout << "Name: " << deserializedData->name << std::endl;
		std::cout << "Value " << deserializedData->value << std::endl;
	}
	else {
		std::cout << "Serialization and deserialization failed" << std::endl;
	}
	return 0;
}