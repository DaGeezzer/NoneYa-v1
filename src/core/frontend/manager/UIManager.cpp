#include "UIManager.hpp"

namespace YimMenu
{
    void UIManager::AddSubmenuImpl(const std::shared_ptr<Submenu>&& submenu)
    {
        if (!m_ActiveSubmenu)
            m_ActiveSubmenu = submenu;

        m_Submenus.push_back(std::move(submenu));
    }

    void UIManager::SetActiveSubmenuImpl(const std::shared_ptr<Submenu> Submenu)
    {
        m_ActiveSubmenu = Submenu;
    }

    void UIManager::DrawImpl()
    {
        auto pos = ImGui::GetCursorPos();

<<<<<<< HEAD
        if (ImGui::BeginChild("##submenus", ImVec2(80, ImGui::GetContentRegionAvail().y - 20), true))
=======
        if (ImGui::BeginChild("##submenus", ImVec2(120, ImGui::GetContentRegionAvail().y - 20), true))
>>>>>>> horsemenu-pr7
        {
            for (auto& submenu : m_Submenus)
            {
                if (ImGui::Selectable(submenu->m_Name.data(), (submenu == m_ActiveSubmenu)))
                {
                    SetActiveSubmenu(submenu);
                }
            }
        }
        ImGui::EndChild();
<<<<<<< HEAD

        ImGui::TextColored(ImVec4(0.0f, 0.75f, 1.0f, 1.0f), "Grym"); // Electric Blue (R, G, B, A)
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Works"); // Electric Yellow (R, G, B, A)

        pos.y -= 20; // Reduced upward offset from 20 to 20 (no change, already reduced)
        ImGui::SetCursorPos(ImVec2(pos.x + 125 - 45, pos.y)); // Shifted X for "minisubmenus" LEFT by 45 pixels (increased from 35) - FURTHER LEFT SHIFT

        if (ImGui::BeginChild("##minisubmenus", ImVec2(0, 45), true, ImGuiWindowFlags_NoScrollbar))
        {
            if (m_ActiveSubmenu)
                m_ActiveSubmenu->DrawCategorySelectors();
        }
        ImGui::EndChild();

        ImGui::SetCursorPos(ImVec2(pos.x + 130 - 45, pos.y + 45 + 4)); // Shifted X for "options" LEFT by 45 pixels (increased from 35)
=======
        
        // Display "b0rk3d & f0rk3d" on the same line with different colors
        ImGui::TextColored(ImVec4(0.0f, 0.75f, 1.0f, 1.0f), "b0rk3d"); // Electric Blue (R, G, B, A)
        ImGui::SameLine(); // Keep the next text on the same line
        ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "&"); // Red "&" (R, G, B, A)
        ImGui::SameLine(); // Keep the next text on the same line
        ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "f0rk3d"); // Electric Yellow (R, G, B, A)

        pos.y -= 28;
        ImGui::SetCursorPos(ImVec2(pos.x + 130, pos.y));

        if (ImGui::BeginChild("##minisubmenus", ImVec2(0, 50), true, ImGuiWindowFlags_NoScrollbar))
        {
            if (m_ActiveSubmenu)
                m_ActiveSubmenu->DrawCategorySelectors();
        }
        ImGui::EndChild();

        ImGui::SetCursorPos(ImVec2(pos.x + 130, pos.y + 60));

>>>>>>> horsemenu-pr7
        if (ImGui::BeginChild("##options", ImVec2(0, 0), true))
        {
            if (m_OptionsFont)
                ImGui::PushFont(m_OptionsFont);

            if (m_ActiveSubmenu)
                m_ActiveSubmenu->Draw();

            if (m_OptionsFont)
                ImGui::PopFont();
        }
<<<<<<< HEAD
        ImGui::EndChild();
    }

    std::shared_ptr<Submenu> UIManager::GetActiveSubmenuImpl()
    {
        if (m_ActiveSubmenu)
        {
            return m_ActiveSubmenu;
        }

        return nullptr;
    }

    std::shared_ptr<Category> UIManager::GetActiveCategoryImpl()
    {
        if (m_ActiveSubmenu)
        {
            return m_ActiveSubmenu->GetActiveCategory();
        }

=======

        ImGui::EndChild();
    }

    std::shared_ptr<Submenu> UIManager::GetActiveSubmenuImpl()
    {
        if (m_ActiveSubmenu)
        {
            return m_ActiveSubmenu;
        }

        return nullptr;
    }

    std::shared_ptr<Category> UIManager::GetActiveCategoryImpl()
    {
        if (m_ActiveSubmenu)
        {
            return m_ActiveSubmenu->GetActiveCategory();
        }

>>>>>>> horsemenu-pr7
        return nullptr;
    }
}