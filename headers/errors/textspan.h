#pragma once

/**
 * @file textspan.h
 * @brief Contains the declaration of the TextSpan struct.
 */

 /**
  * @brief Represents a span of text.
  *
  * The TextSpan struct is responsible for representing a span of text.
  * It provides methods for getting the starting position, length, and ending position of the text span.
  */
struct TextSpan {
public:
    /**
     * @brief Constructs a TextSpan object.
     * @param start The starting position of the text span.
     * @param length The length of the text span.
     */
    TextSpan(int start, int length);

    /**
     * @brief Gets the starting position of the text span.
     * @return The starting position.
     */
    int getStart();

    /**
     * @brief Gets the length of the text span.
     * @return The length.
     */
    int getLength();

    /**
     * @brief Gets the ending position of the text span.
     * @return The ending position.
     */
    int getEnd();

    /**
     * @brief Default constructor for the TextSpan struct.
     */
    TextSpan() = default;

private:
    int start;  // The starting position of the text span.
    int length; // The length of the text span.
};
