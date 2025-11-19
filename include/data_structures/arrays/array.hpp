#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>
#include <stdexcept>

namespace dsa_handbook
{
/**
 * @class Array
 * @brief A fixed-size generic array container with bounds checking.
 *
 * This template class provides a type-safe, fixed-size array wrapper with
 * runtime bounds checking on element access.
 *
 * @tparam T The type of elements stored in the array
 * @tparam N The fixed size of the array at compile-time
 *
 * @note Elements are default-initialized during construction.
 */
template <typename T, std::size_t N>
class Array
{
  public:
    /**
     * @brief Constructs an Array with all elements default-initialized.
     */
    Array() : data{} {}

    /**
     * @brief Accesses element at the given index with bounds checking.
     *
     * @param index The position of the element to access
     * @return A mutable reference to the element at the specified index
     * @throws std::out_of_range if index >= N
     */
    T& operator[](std::size_t index)
    {
        // implicit bounds checking
        if (index >= N)
        {
            throw std::out_of_range("Index out of bounds");
        }

        return data[index];
    }

    /**
     * @brief Accesses element at the given index with bounds checking (const version).
     *
     * @param index The position of the element to access
     * @return A const reference to the element at the specified index
     * @throws std::out_of_range if index >= N
     */
    const T& operator[](std::size_t index) const
    {
        // implicit bounds checking
        if (index >= N)
        {
            throw std::out_of_range("Index out of bounds");
        }

        return data[index];
    }

    /**
     * @brief Returns the size of the array.
     *
     * @return The fixed size N of the array
     */
    std::size_t size() const
    {
        return N;
    }

    /**
     * @brief Returns a pointer to the underlying data.
     *
     * @return A pointer to the first element of the array
     */
    T* data_ptr()
    {
        return data;
    }

    /**
     * @brief Returns a const pointer to the underlying data.
     *
     * @return A const pointer to the first element of the array
     */
    const T* data_ptr() const
    {
        return data;
    }

  private:
    T data[N]; ///< The underlying fixed-size array
};
} // namespace dsa_handbook

#endif // ARRAY_HPP
