/**
 * @file LinkedList.h
 * @brief This file contains the implementation of a templated LinkedList class.
 *
 * The LinkedList class defined in this file is a fundamental data structure in computer science.
 * It provides a templated, dynamic collection of elements in a sequential manner. This implementation
 * allows for basic operations such as insertion and traversal, catering to a variety of use cases
 * where a lightweight and flexible linear data structure is required.
 *
 * The templated nature of this class makes it suitable for storing any data type, providing
 * flexibility and reusability in different contexts. It's implemented in a namespace to avoid
 * name clashes and maintain a clean structure.
 *
 * Key Features:
 * - Templated for generic data types.
 * - Simple and intuitive interface for common operations like insertion.
 * - Lightweight and self-contained, with no external dependencies.
 *
 * Usage:
 * This header should be included in projects where a basic linked list structure is needed.
 * It's designed to be easy to integrate and use in various C++ applications.
 *
 * @todo Add support for multiple arguments in constructor
 *
 * @note This implementation adheres to the Google C++ Style Guide.
 * @author DWI
 * @date 2021-12-12
 */

#ifndef SAAB_LIBRARY_LINKED_LIST
#define SAAB_LIBRARY_LINKED_LIST

#include <cstdint>
#include <iostream>
namespace saab
{
namespace library
{

template <typename T>
class LinkedList
{
  public:
    /**
     * @brief Default constructor. Initializes an empty linked list.
     */
    LinkedList() : head_{nullptr} {}

    /**
     * @brief Inserts a value into the linked list in sorted order.
     *
     * @param value The value to be inserted.
     */
    void Insert(T value) noexcept
    {
        Node** current = &head_;
        while (*current && (*current)->value_ < value)
        {
            current = &((*current)->next_);
        }
        *current = new Node(value, *current);
    }

    /**
     * @brief Prints all values in the linked list in a readable format.
     */
    void Print() const noexcept
    {
        Node* current = head_;
        while (current)
        {
            std::cout << current->value_ << " ";
            current = current->next_;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Deletes a node at the specified index in the linked list.
     *
     * @param index The zero-based index of the node to be deleted.
     *
     * @return `true` if deletion was successful, `false` otherwise.
     */
    bool DeleteAtIndex(const std::int32_t index) noexcept
    {
        if (index < 0)
        {
            return false;
        }
        Node** current = &head_;
        for (int i = 0; *current && i < index; ++i)
        {
            current = &((*current)->next_);
        }
        if (*current)
        {
            Node* temp = *current;
            *current = (*current)->next_;
            delete temp;
            return true;
        }
        return false;
    }

    /**
     * @brief Deletes all nodes with a specific value from the linked list.
     *
     * @param value The value of the nodes to be deleted.
     *
     * @return `true` if at least one node was deleted, `false` otherwise.
     */
    bool DeleteAllValues(T value) noexcept
    {
        Node** current = &head_;
        bool found{false};

        while (*current)
        {
            if ((*current)->value_ == value)
            {
                Node* temp = *current;
                *current = (*current)->next_;
                delete temp;
                found = true;
            }
            else
            {
                current = &((*current)->next_);
            }
        }
        return found;
    }

    /**
     * @brief Retrieves the value stored at the specified index in the linked list.
     *
     * @param index The zero-based index of the node whose value is to be retrieved.
     *
     * @return The value stored at the specified index.
     *
     * @throw `std::out_of_range` if the index is out of range.
     */
    T at(const std::int32_t index) const
    {
        if (this->Length() < index || index < 0)
        {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head_;
        for (std::int32_t i = 0; current && i < index; ++i)
        {
            current = current->next_;
        }
        return current->value_;
    }

    /**
     * @brief Calculates the length of the linked list.
     *
     * @return The number of nodes in the linked list.
     */
    std::int32_t Length() const noexcept
    {
        Node* current = head_;
        std::int32_t length{0};
        while (current)
        {
            ++length;
            current = current->next_;
        }
        return length;
    }

    /**
     * @brief Destructor for the LinkedList class.
     *
     * Destroys the LinkedList object and frees all associated memory.
     */
    ~LinkedList() { ClearList(); }

    /**
     * @brief Copy constructor for the LinkedList class.
     *
     * Creates a new LinkedList as a deep copy of another LinkedList.
     *
     * @param other The LinkedList object to be copied.
     */
    LinkedList(const LinkedList& other) noexcept
    {
        head_ = nullptr;
        CopyList(other);
    }

    /**
     * @brief Copy assignment operator for the LinkedList class.
     *
     * Replaces the contents of the LinkedList with a copy of the contents of another LinkedList.
     *
     * @param other The LinkedList object to be copied.
     *
     * @return A reference to the current LinkedList object.
     */
    LinkedList& operator=(const LinkedList& other)
    {
        if (this != &other)
        {
            ClearList();      // clear all the data in current Node.
            CopyList(other);  // call deep copy constructor
        }
        return *this;
    }

    /**
     * @brief Move constructor for the LinkedList class.
     *
     * Creates a new LinkedList by moving the contents of another LinkedList.
     *
     * @param other The LinkedList object to be moved.
     */
    LinkedList(LinkedList&& other) noexcept
    {
        head_ = nullptr;
        MoveList(std::move(other));
    }

    /**
     * @brief Move assignment operator for the LinkedList class.
     *
     * Replaces the contents of the LinkedList with the contents of another LinkedList, which is moved rather than
     * copied.
     *
     * @param other The LinkedList object to be moved.
     *
     * @return A reference to the current LinkedList object.
     */
    LinkedList& operator=(LinkedList&& other) noexcept
    {
        if (this != &other)
        {
            ClearList();
            MoveList(std::move(other));
        }
        return *this;
    }

  private:  // Methods
    void ClearList() noexcept
    {
        Node* current_node = head_;
        while (current_node)
        {
            Node* next = current_node->next_;
            delete current_node;
            current_node = next;
        }
    }

    void CopyList(const LinkedList& other) noexcept
    {
        Node* current = other.head_;
        Node* previous = nullptr;
        while (current)
        {
            Node* newNode = new Node(current->value_);
            if (previous == nullptr)
            {
                head_ = newNode;
            }
            else
            {
                previous->next_ = newNode;
            }
            previous = newNode;
            current = current->next_;
        }
    }

    void MoveList(LinkedList&& other) noexcept
    {
        this->head_ = other.head_;
        other.head_ = nullptr;
    }

    struct Node
    {
      public:
        Node(T data, Node* next = nullptr) : value_{data}, next_{next} {}
        Node() : Node(0, nullptr) {}

        T value_;
        Node* next_;
    };

  private:  // Member variables
    Node* head_;
};

}  // namespace library
}  // namespace saab

#endif  // SAAB_LIBRARY_LINKED_LIST