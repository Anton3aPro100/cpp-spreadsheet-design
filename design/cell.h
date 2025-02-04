#pragma once

#include "common.h"
#include "formula.h"
class Sheet : public SheetInterface;

class Cell : public CellInterface {
public:
    Cell(Sheet& sheet);
    ~Cell();

    void Set(std::string text);
    void Clear();

    Value GetValue() const override;
    std::string GetText() const override;
    
    
    void GetAllParents(std::set<Position>& parents) const;
    std::set<Position> GetIngoingEdges() const;
    bool HasNoLinkOnParent(std::set<Position>& validated_vertices, const std::set<Position>& parents) const;
    
    bool HasValue() const;
    void InvalideValue();

    private:
    

    bool is_it_formula_ = false;
    std::string text_;
    std::unique_ptr<FormulaInterface> formula_;
    
    Sheet& sheet_;
    std::vector<Position> outgoing_edges_;
    std::set<Position> ingoing_edges_;
    
    mutable std::optional<FormulaInterface::Value> value_;

    

//можете воспользоваться нашей подсказкой, но это необязательно.
/*    class Impl;
    class EmptyImpl;
    class TextImpl;
    class FormulaImpl;
    std::unique_ptr<Impl> impl_;
*/
};