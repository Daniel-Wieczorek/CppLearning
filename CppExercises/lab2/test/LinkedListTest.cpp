#include <catch2/catch_all.hpp>
#include "../LinkedList.h"

#include <iostream>

using namespace saab::library;

TEST_CASE("LinkedList Insert and Print", "[LinkedList]")
{
    LinkedList<std::int32_t> list;
    SECTION("Insert into Empty List")
    {
        list.Insert(5);
        REQUIRE(list.Length() == 1);
    }
    SECTION("Insert at Beginning")
    {
        list.Insert(10);
        list.Insert(5);
        REQUIRE(list.at(0) == 5);
    }
    SECTION("Insert at End")
    {
        list.Insert(5);
        list.Insert(10);
        REQUIRE(list.at(1) == 10);
    }
    SECTION("Insert in Middle")
    {
        list.Insert(5);
        list.Insert(15);
        list.Insert(10);
        REQUIRE(list.at(1) == 10);
    }
}

TEST_CASE("LinkedList DeleteAtIndex", "[LinkedList]")
{
    LinkedList<std::int32_t> list;
    list.Insert(5);
    list.Insert(10);
    list.Insert(15);
    SECTION("Delete from Empty List")
    {
        LinkedList<std::int32_t> emptyList;
        REQUIRE_FALSE(emptyList.DeleteAtIndex(0));
    }
    SECTION("Delete Head")
    {
        REQUIRE(list.DeleteAtIndex(0));
        REQUIRE(list.at(0) == 10);
    }
    SECTION("Delete Last Element")
    {
        REQUIRE(list.DeleteAtIndex(2));
        REQUIRE(list.Length() == 2);
    }
    SECTION("Delete Middle Element")
    {
        REQUIRE(list.DeleteAtIndex(1));
        REQUIRE(list.at(1) == 15);
    }
    SECTION("Invalid Index") { REQUIRE_FALSE(list.DeleteAtIndex(3)); }
}

TEST_CASE("LinkedList DeleteAllValues", "[LinkedList]")
{
    LinkedList<std::int32_t> list;
    list.Insert(5);
    list.Insert(5);
    list.Insert(10);
    SECTION("Delete Non-Existent Value") { REQUIRE_FALSE(list.DeleteAllValues(20)); }
    SECTION("Delete Single Occurrence")
    {
        REQUIRE(list.DeleteAllValues(10));
        REQUIRE(list.Length() == 2);
    }
    SECTION("Delete Multiple Occurrences")
    {
        REQUIRE(list.DeleteAllValues(5));
        REQUIRE(list.Length() == 1);
    }
}

TEST_CASE("LinkedList Copy Constructor", "[LinkedList]")
{
    SECTION("Copying an empty list")
    {
        LinkedList<std::int32_t> originalList;
        LinkedList<std::int32_t> copiedList(originalList);

        REQUIRE(copiedList.Length() == 0);  // Copied list should be empty
    }

    SECTION("Copying a non-empty list")
    {
        LinkedList<std::int32_t> originalList;
        originalList.Insert(1);
        originalList.Insert(2);
        originalList.Insert(3);

        LinkedList<std::int32_t> copiedList(originalList);

        REQUIRE(copiedList.Length() == originalList.Length());
        REQUIRE(copiedList.at(0) == 1);
        REQUIRE(copiedList.at(1) == 2);
        REQUIRE(copiedList.at(2) == 3);
    }

    SECTION("Modifying original list after copying")
    {
        LinkedList<std::int32_t> originalList;
        originalList.Insert(1);
        originalList.Insert(2);

        LinkedList<std::int32_t> copiedList(originalList);
        originalList.Insert(3);

        REQUIRE(originalList.Length() == 3);
        REQUIRE(copiedList.Length() == 2);
    }

    SECTION("Modifying copied list after copying")
    {
        LinkedList<std::int32_t> originalList;
        originalList.Insert(1);
        originalList.Insert(2);

        LinkedList<std::int32_t> copiedList(originalList);
        copiedList.Insert(3);

        REQUIRE(originalList.Length() == 2);
        REQUIRE(copiedList.Length() == 3);
    }
}
