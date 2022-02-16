#include "gtest/gtest.h"
#include "functions.h"

TEST(testId, getId){
    flowerbed testObject(1, "circle", std::list<std::string>{""});
    ASSERT_EQ(testObject.getId(), 1);
}
TEST(testShape, getShape){
    flowerbed testObject(1, "circle", std::list<std::string>{""});;
    ASSERT_EQ(testObject.getShape(), 0);
    ASSERT_EQ(testObject.strShape(), "circle");
}
TEST(testFlowers, getAndAddFlowers){
    flowerbed testObject(1, "circle", std::list<std::string>{"rose", "sunflower", "orchid"});
    std::list<std::string>testList{ "rose", "sunflower", "orchid" };
    ASSERT_EQ(testObject.getFlowers(), testList);
    ASSERT_EQ(testObject.strFlowers(), "rose sunflower orchid ");
    testObject.addFlower("rose");
    ASSERT_EQ(testObject.strFlowers(), "rose sunflower orchid rose ");
}
TEST(testGettingFromFile, testgetFlowerbedsFromFile){
    std::list<flowerbed> testList = flowerbed::getFlowerbedsFromFile("testInput.txt");
    ASSERT_EQ(testList.front().getId(), 1);
    ASSERT_EQ(testList.front().strShape(), "square");
    ASSERT_EQ(testList.front().strFlowers(), "cornflower lily ");
    ASSERT_EQ(testList.back().getId(), 6);
    ASSERT_EQ(testList.back().strShape(), "circle");
    ASSERT_EQ(testList.back().strFlowers(), "rose sunflower ");
}
TEST(testSort, sortByShape){
    std::list<flowerbed> testList = flowerbed::getFlowerbedsFromFile("testInput.txt");
    flowerbed::sortByShape(testList);
    ASSERT_EQ(testList.front().strShape(), "circle");
    ASSERT_EQ(testList.back().strShape(), "rhombus");
}
TEST(testConvert, listToMultimap){
    std::list<flowerbed> testList = flowerbed::getFlowerbedsFromFile("testInput.txt");
    std::multimap<flowerbed::shapes, flowerbed> testMap;
    testMap = flowerbed::listToMultimap(testList);
    ASSERT_EQ(testMap.begin()->second.getId(), 2);
    ASSERT_EQ(testMap.begin()->second.strShape(), "circle");
    ASSERT_EQ(testMap.begin()->second.strFlowers(), "cornflower lily ");
    ASSERT_EQ(testMap.rbegin()->second.getId(), 3);
    ASSERT_EQ(testMap.rbegin()->second.strShape(), "rhombus");
    ASSERT_EQ(testMap.rbegin()->second.strFlowers(), "cornflower lily ");
}
TEST(testingMethods, testFlowersMax){
    std::list<flowerbed> testList = flowerbed::getFlowerbedsFromFile("testInput.txt");
    std::multimap<flowerbed::shapes, flowerbed> testMap;
    testMap = flowerbed::listToMultimap(testList);
    flowerbed testObject1(5, "circle", std::list<std::string>{"cornflower", "lily", "rose", "sunflower"});
    flowerbed testObject2 = flowerbed::flowersMax(testMap);
    ASSERT_EQ(testObject1.getId(), testObject2.getId());
    ASSERT_EQ(testObject1.strShape(), testObject2.strShape());
    ASSERT_EQ(testObject1.strFlowers(), testObject2.strFlowers());
}
TEST(testingMethods, testFlowerbedsByNumber){
    std::list<flowerbed> testList = flowerbed::getFlowerbedsFromFile("testInput.txt");
    std::multimap<flowerbed::shapes, flowerbed> testMap;
    testMap = flowerbed::listToMultimap(testList);
    std::list<flowerbed> testAnswer = flowerbed::flowerbedsByNumber(testMap, 2);
    ASSERT_EQ(testAnswer.front().getId(), 2);
    ASSERT_EQ(testAnswer.front().strShape(), "circle");
    ASSERT_EQ(testAnswer.front().strFlowers(), "cornflower lily ");
    ASSERT_EQ(testAnswer.back().getId(), 3);
    ASSERT_EQ(testAnswer.back().strShape(), "rhombus");
    ASSERT_EQ(testAnswer.back().strFlowers(), "cornflower lily ");
}
TEST(testingMethods, testoneKindFlowerbeds){
    std::list<flowerbed> testList = flowerbed::getFlowerbedsFromFile("testInput.txt");
    std::multimap<flowerbed::shapes, flowerbed> testMap;
    testMap = flowerbed::listToMultimap(testList);
    flowerbed testFlowerbed = flowerbed::oneKindFlowerbeds(testMap);
    ASSERT_EQ(testFlowerbed.getId(), 4);
    ASSERT_EQ(testFlowerbed.strShape(), "circle");
    ASSERT_EQ(testFlowerbed.strFlowers(), "lily lily ");
    testList = flowerbed::getFlowerbedsFromFile("testInput2.txt");
    testMap = flowerbed::listToMultimap(testList);
    ASSERT_ANY_THROW(flowerbed::oneKindFlowerbeds(testMap));
}
TEST(testMethods, testMaxKind){
    std::list<flowerbed> testList = flowerbed::getFlowerbedsFromFile("testInput.txt");
    std::multimap<flowerbed::shapes, flowerbed> testMap;
    testMap = flowerbed::listToMultimap(testList);
    flowerbed testFlowerbed = flowerbed::maxKind(testMap);
    ASSERT_EQ(testFlowerbed.getId(), 4);
    ASSERT_EQ(testFlowerbed.strShape(), "circle");
    ASSERT_EQ(testFlowerbed.strFlowers(), "lily lily ");
}
TEST(testMethods, testFlowerbedsWithoutFlower){
    std::list<flowerbed> testList = flowerbed::getFlowerbedsFromFile("testInput.txt");
    std::multimap<flowerbed::shapes, flowerbed> testMap;
    testMap = flowerbed::listToMultimap(testList);
    std::list<flowerbed> testAnswer = flowerbed::flowerbedsWithoutFlower(testMap, "lily");
    ASSERT_EQ(testAnswer.front().getId(), 6);
    ASSERT_EQ(testAnswer.front().strShape(), "circle");
    ASSERT_EQ(testAnswer.front().strFlowers(), "rose sunflower ");
}
TEST(testFunctions, testNumberOnCircleFlowerbeds){
    std::list<flowerbed> testList = flowerbed::getFlowerbedsFromFile("testInput.txt");
    std::multimap<flowerbed::shapes, flowerbed> testMap;
    testMap = flowerbed::listToMultimap(testList);
    ASSERT_EQ(numberOfflowersOnCircleFlowerbeds(testMap), 10);
    flowerbed fb = testList.front();
    ASSERT_EQ(fb(testMap), 10);
}
TEST(testFuntions, testFindByNumberOfFlowers){
    std::list<flowerbed> testList = flowerbed::getFlowerbedsFromFile("testInput.txt");
    std::multimap<flowerbed::shapes, flowerbed> testMap;
    testMap = flowerbed::listToMultimap(testList);
    testList = findByNumberOfFlowers(testMap, 4);
    ASSERT_EQ(testList.front().getId(), 5);
    ASSERT_EQ(testList.front().strShape(), "circle");
    ASSERT_EQ(testList.front().strFlowers(), "cornflower lily rose sunflower ");
    flowerbed fb = testList.front();
    ASSERT_EQ(fb(testMap, 4).front().getId(), 5);
    ASSERT_EQ(fb(testMap, 4).front().strShape(), "circle");
    ASSERT_EQ(fb(testMap, 4).front().strFlowers(), "cornflower lily rose sunflower ");
}
TEST(testFunctions, testFindByShape){
    std::list<flowerbed> testList = flowerbed::getFlowerbedsFromFile("testInput.txt");
    std::multimap<flowerbed::shapes, flowerbed> testMap;
    testMap = flowerbed::listToMultimap(testList);
    testList = findByShape(testMap, "rhombus");
    ASSERT_EQ(testList.front().getId(), 3);
    ASSERT_EQ(testList.front().strShape(), "rhombus");
    ASSERT_EQ(testList.front().strFlowers(), "cornflower lily ");
    flowerbed fb = testList.front();
    ASSERT_EQ(fb(testMap, "rhombus").front().getId(), 3);
    ASSERT_EQ(fb(testMap, "rhombus").front().strShape(), "rhombus");
    ASSERT_EQ(fb(testMap, "rhombus").front().strFlowers(), "cornflower lily ");
}
TEST(testOperators, comparisonOperator){
    flowerbed testFlowerbed1(1, "circle", std::list<std::string>{"rose", "sonflower", "orhcid"});
    flowerbed testFlowerbed2(2, "circle", std::list<std::string>{"rose", "sonflower", "orhcid"});
    flowerbed testFlowerbed3(3, "square", std::list<std::string>{"rose", "sonflower", "orhcid"});
    flowerbed testFlowerbed4(4, "circle", std::list<std::string>{"rose", "sonflower"});
    ASSERT_TRUE(testFlowerbed1 == testFlowerbed2);
    ASSERT_FALSE(testFlowerbed1 == testFlowerbed3);
    ASSERT_FALSE(testFlowerbed1 == testFlowerbed4);
}

int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}