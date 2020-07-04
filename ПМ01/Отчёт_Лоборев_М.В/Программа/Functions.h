#pragma once

void readFileBuyer(std::vector <Buyer>& buyer);
void readFileManager(std::vector <Manager>& manager);
void readFileCar(std::vector <Car>& car);
void readFileSales(std::vector <Sales>& sales);
void averageTransactionAmount(std::vector <Sales>& sales);
void EachCarSold(std::vector <Sales>& sales, std::vector <Car>& car);