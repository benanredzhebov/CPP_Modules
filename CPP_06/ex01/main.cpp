/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:40:12 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/23 14:48:39 by beredzhe         ###   ########.fr       */
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

	// Deserialize the raw value back to a Data pointer
	Data* deserializedData = Serializer::deserialize(raw);

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