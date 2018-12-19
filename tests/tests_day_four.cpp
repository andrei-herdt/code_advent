#include <gmock/gmock.h>

TEST(day_four, part_one) {
    const std::vector<std::string> claims{
        "[1518 - 11 - 01 00:00] Guard #10 begins shift"
        "[1518 - 11 - 01 00:05] falls asleep [1518 - 11 - 01 00:25] wakes up"
        "[1518 - 11 - 01 00:30] falls asleep [1518 - 11 - 01 00:55] wakes up"
        "[1518 - 11 - 01 23:58] Guard #99 begins shift"
        "[1518 - 11 - 02 00:40] falls asleep [1518 - 11 - 02 00:50] wakes up"
        "[1518 - 11 - 03 00:05] Guard #10 begins shift"
        "[1518 - 11 - 03 00:24] falls asleep [1518 - 11 - 03 00:29] wakes up"
        "[1518 - 11 - 04 00:02] Guard #99 begins shift"
        "[1518 - 11 - 04 00:36] falls asleep [1518 - 11 - 04 00:46] wakes up"
        "[1518 - 11 - 05 00:03] Guard #99 begins shift"
        "[1518 - 11 - 05 00:45] falls asleep [1518 - 11 - 05 00:55] wakes up"};

    /*
    Find guard with most sleeping time
     Extract gaurd id, sleeping time period
     Convert into keys of [id, 0-59]
     Populate 2dimensional multimap with ones for every sleeping minute
     Sum of sleeping minutes for each instance of specific id over all time
     Take max -> id
     Sum of sleeping minutes for each minute over all instances of specific
     id Take max -> minute
    */

    int id = 10;
    int minute = 24;
    ASSERT_EQ(id * minute, 240);
}
