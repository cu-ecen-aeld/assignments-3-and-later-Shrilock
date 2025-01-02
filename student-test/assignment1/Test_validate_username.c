#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
* This function should:
*   1) Call the my_username() function in autotest-validate.c to get your hard coded username.
*   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
*       the assignment autotest submodule at assignment-autotest/test/assignment1/
*   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE to verify the two strings are equal.  See
*       the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
*/
void test_validate_my_username()
{
    /**
     * TODO: Replace the line below with your code here as described above to verify your /conf/username.txt 
     * config file and my_username() functions are setup properly
     */
    //TEST_ASSERT_TRUE_MESSAGE(false,"AESD students, please fix me!");

      // Call my_username() to get the hard-coded username
    const char *hardcoded_username = my_username();

    // Call malloc_username_from_conf_file() to get the username from the configuration file
    char *config_username = malloc_username_from_conf_file();

    // Use Unity assertion to verify that the two strings are equal
    TEST_ASSERT_EQUAL_STRING_MESSAGE(
        hardcoded_username, 
        config_username, 
        "The username from the configuration file does not match the hard-coded username"
    );

    // Free the memory allocated by malloc_username_from_conf_file()
    free(config_username);
}
