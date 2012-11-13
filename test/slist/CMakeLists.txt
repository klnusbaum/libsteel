INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/test)

ADD_UNIT_TEST(SlistInitTest slist_init_test.c)
ADD_UNIT_TEST(SlistHeadInsertTest slist_head_insert_test.c)
ADD_UNIT_TEST(SlistTailInsertTest slist_tail_insert_test.c)
ADD_UNIT_TEST(SlistAfterInsertTest slist_after_insert_test.c)
ADD_UNIT_TEST(SlistRemoveHeadTest slist_remove_head_test.c)

