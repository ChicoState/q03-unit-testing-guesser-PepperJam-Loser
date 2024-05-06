/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


TEST(GuesserTest, FAIL_WRONGGUESS)
{
	Guesser test("lex");
	bool guess = test.match("TEST");
	ASSERT_TRUE(guess);
}

TEST(GuesserTest, FAIL_OVERGUESS)
{
	Guesser test("testbreak");
	bool guess = false;
	guess = test.match("TEST");
	guess = test.match("TEST");
	guess = test.match("TEST");
	guess = test.match("testbreak");
	ASSERT_TRUE(guess);
}

TEST(GuesserTest, FAIL_RESETGUESS)
{
	Guesser test("testbreak");
	bool guess = false;
	guess = test.match("TEST");
	guess = test.match("TEST");
	guess = test.match("testbreak");
	guess = test.match("TEST");
	guess = test.match("TEST");
	guess = test.match("TEST");
	guess = test.match("testbreak");
	ASSERT_TRUE(guess);
}

TEST(GuesserTest, FAIL_GUESSOVER3)
{
	Guesser test("testbreak");
	bool guess = false;
	guess = test.match("testbreaking");
	ASSERT_TRUE(guess);
}

TEST(GuesserTest, FAIL_PASSOVER3)
{
	Guesser test("testbreaking");
	bool guess = false;
	guess = test.match("testbreak");
	ASSERT_TRUE(guess);
}

TEST(GuesserTest, FAIL_CUTOFF)
{
	Guesser test("123456781234567812345678123456789");
	bool guess = test.match("12345678123456781234567812345678912");
	ASSERT_TRUE(guess);
}

TEST(GuesserTest, PASS_GUESSUNDER3)
{
	Guesser test("testbreak");
	bool guess = false;
	guess = test.match("testbreakin");
	ASSERT_TRUE(guess);
}

TEST(GuesserTest, PASS_PASSUNDER3)
{
	Guesser test("testbreakin");
	bool guess = false;
	guess = test.match("testbreak");
	ASSERT_TRUE(guess);
}

TEST(GuesserTest, PASS_SAMEGUESS)
{
	Guesser test("TEST");
	bool guess = test.match("TEST");
	ASSERT_TRUE(guess);
}

TEST(GuesserTest, PASS_CUTOFF)
{
	Guesser test("123456781234567812345678123456789");
	bool guess =  test.match("12345678123456781234567812345678");
	ASSERT_TRUE(guess);
}

TEST(GuesserTest, PASS_RESETGUESS)
{
	Guesser test("testbreak");
	bool guess = false;
	guess = test.match("TEST");
	guess = test.match("TEST");
	guess = test.match("testbreak");
	guess = test.match("TEST");
	guess = test.match("TEST");
	guess = test.match("testbreak");
	ASSERT_TRUE(guess);
}