#include<memory>
#include<iostream>
#include<stdexcept>
#include<filesystem>

#include<arrow/api.h>
#include<arrow/array.h>

using namespace std;
using namespace std::__fs;

arrow::Status inner_main() {
    std::vector<int64_t> data{1,2,3,4};
    auto arr = std::make_shared<arrow::Int64Array>(data.size(), arrow::Buffer::Wrap(data));
    std::cout << arr->ToString() << std::endl;

    return arrow::Status::OK();
}

int main()
{
    auto status = inner_main();
    return status.ok() ? 0 : 1;
}
