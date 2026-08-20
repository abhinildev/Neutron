#include<iostream>
#include<fstream>
#include<sstream>
#include<optional>
#include<vector>
#include "parser.hpp"
#include "tokenization.hpp"
#include "generation.hpp"
// creates the assembly by reading the tokens temporary for now and trees will be created later on

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cerr<<"Incorrect usage"<<std::endl;
        std::cerr<<"neutro <input.neu>"<<std::endl;
        return EXIT_FAILURE;
    }
    std::string contents;
    
    std::stringstream contents_stream;
    {   std::fstream input(argv[1], std::ios::in);
        contents_stream<<input.rdbuf();
        contents=contents_stream.str();
    }
    //std::cout<<contents<<std::endl;

    //std::cout<<"The path is "<<argv[1]<<std::endl;
    Tokenizer tokenizer(
        std::move(contents)
    );

    std::vector<Token> tokens=tokenizer.tokenize();
  Parser parser(std::move(tokens));
    std::optional<NodeExit> tree=parser.parse();
    if(!tree.has_value()){
        std::cerr<<"No exit statement found"<<std::endl;
        exit(EXIT_FAILURE);
    }

  Generator generator(tree.value());
    //std::cout<<"tokenizing done"<<std::endl;
    //std::cout<<tokens_to_asm(tokens)<<std::endl;
    {
        std::fstream file("./Assembly/out.asm",std::ios::out);
        file<<generator.generate();
    }
    return EXIT_SUCCESS;
}
