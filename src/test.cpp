#include <gtest/gtest.h>
// #include "employee.hpp"
#include "database.hpp"

struct DatabaseTest : ::testing::Test
{
	Database db;
};

TEST(DatabaseTest, DisplayEmptyDb) {
	Database db;
	auto content = db.show();
	auto expected = "";
	EXPECT_EQ(content, expected);
}

TEST(DatabaseTest, DisplayNonEmptyDb) {
	Employee adam {"Adam", "Kowalsko", "ul. Dluga 15, 45-030 Opole", 123497, "HR Specialist", Gender::Male};
	Database db;
	db.add(adam);

    auto content = db.show();
	auto expected = "Adam Kowalsko; ul. Dluga 15, 45-030 Opole; 123497; 11223300558; Male";
	EXPECT_EQ(content, expected);
}