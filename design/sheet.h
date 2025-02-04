#pragma once

#include "cell.h"
#include "common.h"

#include <functional>

class Sheet : public SheetInterface {
public:
    ~Sheet();

    void SetCell(Position pos, std::string text) override;

    const CellInterface* GetCell(Position pos) const override;
    CellInterface* GetCell(Position pos) override;

    void ClearCell(Position pos) override;

    Size GetPrintableSize() const override;

    void PrintValues(std::ostream& output) const override;
    void PrintTexts(std::ostream& output) const override;

	// Можете дополнить ваш класс нужными полями и методами
    
   
    bool IsNoCiclesCreate(Position pos, const std::vector<Position>& outgoing_edges) const;
    
    void Invalide_Values(const std::set<Position>& parents);


    private:
    

    // Можете дополнить ваш класс нужными полями и методами
    
    void AddEmptyColumns(int n);
    void AddEmptyRows(int n);
    void AddEmptyRows(int row, int col); 

    std::vector<std::vector<std::unique_ptr<CellInterface>>> cells_;
    
    /*std::map<int, int> filled_rows_;
    std::map<int, int> filled_cols_;
    int max_row_ = -1;
    int max_col_ = -1;
    */

   
};