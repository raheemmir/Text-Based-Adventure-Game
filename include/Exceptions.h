#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
 * @class cannot_be_null Exceptions/h "Exceptions.h"
 * @brief Exception for when a pointer cnnot be set to the null pointer.
 */
class cannot_be_null : public std::runtime_error {
 public:
  /**
   * @brief Exception for when an object cannot accomodate an Addition.
   * @param errMessage An error message.
   */
  explicit cannot_be_null(const char *errMessage) :
      std::runtime_error(errMessage) {
  }
};

/**
 * @class invalid_identifier Exceptions/h "Exceptions.h"
 * @brief Exception for when an identifier has an invalid format.
 */
class invalid_identifier : public std::runtime_error {
 public:
  /**
   * @Exception for when an identifier has an invalid format.
   * @param errMessage An error message
   */
  explicit invalid_identifier(const char* errMessage) :
  std::runtime_error(errMessage) {
  }
};

/**
 * @class invalid_object Exceptions.h "Exceptions.h"
 * @brief Exception for when an object is not ready to be used or has a problem.
 */
class invalid_object : public std::runtime_error {
 public:
  /**
   * @brief Exception for when an object is not ready to be used or has a problem.
   * @param errMessage An error message.
   */
  explicit invalid_object(const char *errMessage) :
      std::runtime_error(errMessage) {
  }
};

/**
 * @class value_out_of_range Exceptions.h "Exceptions.h"
 * @brief Exception for when a value is not within the set of valid values.
 */
class value_out_of_range : public std::runtime_error {
 public:
  /**
   * Exception for when a value is not within the set of valid values.
   * @param errMessage An error message.
   */
  explicit value_out_of_range(const char *errMessage)
      :
      std::runtime_error(errMessage) {
  }
};
#endif //EXCEPTIONS_H_INCLUDED

