/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:40:12 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/26 09:20:40 by beredzhe         ###   ########.fr       */
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
	// raw += 1; // This will make the pointer invalid
	
	// Deserialize the raw value back to a Data pointer
	Data* deserializedData = Serializer::deserialize(raw);
	
	// Ensure the deserialized pointer is equal to the original pointer
	if (deserializedData == &originalData) {
		std::cout << "Serialization and deserialization successful!" << std::endl;
		std::cout << "Serialized Data (as unsigned long): " << raw << std::endl; // This integer represents the memory address of the Data object.
		std::cout << "Original Data Address: " << &originalData << std::endl;
		std::cout << "After serialization:   " << deserializedData << std::endl;
		 std::cout << "Deserialized content: " << deserializedData->id << ", " \
	<< deserializedData->name << ", " << deserializedData->value << std::endl;
	}
	else {
		std::cout << "Serialization and deserialization failed" << std::endl;
	}
	return 0;
}
