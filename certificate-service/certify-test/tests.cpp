/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "/home/tatiana/Рабочий стол/certificate-service/certify-test/TestSuite.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "TestSuite.h", 15, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testGetServerInitialization : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testGetServerInitialization() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 18, "testGetServerInitialization" ) {}
 void runTest() { suite_MyTestSuite.testGetServerInitialization(); }
} testDescription_suite_MyTestSuite_testGetServerInitialization;

static class TestDescription_suite_MyTestSuite_testGetIDUser : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testGetIDUser() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 34, "testGetIDUser" ) {}
 void runTest() { suite_MyTestSuite.testGetIDUser(); }
} testDescription_suite_MyTestSuite_testGetIDUser;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
