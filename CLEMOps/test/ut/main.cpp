#include "Tester.hpp"

TEST(Nominal, GyroXOperationTest){
	Ref::Tester tester;
	tester.testGyroXCommand();
}

TEST(Nominal, GyroYOperationTest){
	Ref::Tester tester;
	tester.testGyroYCommand();
}

TEST(Nominal, GyroZOperationTest){
	Ref::Tester tester;
	tester.testGyroZCommand();
}

TEST(Nominal, RTCTimeOperationTest){
	Ref::Tester tester;
	tester.testRTCTimeCommand();
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
