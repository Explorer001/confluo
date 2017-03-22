#include "tokens.h"
#include "gtest/gtest.h"

extern std::string res_path_index;
extern std::string res_path_index2;
extern std::string res_path_stream;
extern std::string res_path_logstore;

extern bool filter_fn1(uint64_t& record_id, const unsigned char* record,
                       const uint16_t record_len,
                       const monolog::token_list& list) {
  return record_id % 10 == 0;
}

extern bool filter_fn2(uint64_t& record_id, const unsigned char* record,
                       const uint16_t record_len,
                       const monolog::token_list& list) {
  bool filter = record_id % 10 == 0;
  record_id /= 10;
  return filter;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::string res_path = ".";
  if (argc >= 2)
    res_path = std::string(argv[1]);
  res_path_index = res_path + "/index_latency.txt";
  res_path_index2 = res_path + "/index";
  res_path_stream = res_path + "/stream";
  res_path_logstore = res_path + "/logstore.txt";
  return RUN_ALL_TESTS();
}