#include "Application.h"
#include "imgui.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

namespace MyApp
{
    void SetStandardDeduction(int *standard_deduction, int *curr_income_status)
    {
        if (*curr_income_status == 0 || *curr_income_status == 2)
        {
            *standard_deduction = 13500;
        }
        else if (*curr_income_status == 1 || *curr_income_status == 4)
        {
            *standard_deduction = 27700;
        }
        else if (*curr_income_status == 3)
        {
            *standard_deduction = 20800;
        }
    }

    void RenderIncome(const char *income_status[], static int *curr_income_status, const char *income_status_preview, static int income_status_size, int *tax_owed, int *standard_deduction, int *income_amount, int *adjustment_amount)
    {
        SetStandardDeduction(standard_deduction, curr_income_status);

        if (ImGui::BeginCombo("Income Status", income_status_preview))
        {
            for (int n = 0; n < income_status_size; n++)
            {
                const bool is_selected = (*curr_income_status == n);
                if (ImGui::Selectable(income_status[n], is_selected))
                {
                    *curr_income_status = n;
                    SetStandardDeduction(standard_deduction, curr_income_status);
                }
                if (is_selected)
                {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }

        ImGui::InputInt("Input Income", income_amount);

        // Add additional income options
    }

    void RenderWithholdings(const char *income_frequency[], const char *income_source[], int *curr_income_source, int *curr_income_frequency, const char *income_source_preview, const char *income_frequency_preview, int income_source_size, int income_frequency_size)
    {
        if (ImGui::BeginCombo("Income Source", income_source_preview))
        {
            for (int n = 0; n < income_source_size; n++)
            {
                const bool is_selected = (*curr_income_source == n);
                if (ImGui::Selectable(income_source[n], is_selected))
                {
                    *curr_income_source = n;
                }
                if (is_selected)
                {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }

        if (ImGui::BeginCombo("Income Frequency", income_frequency_preview))
        {
            for (int n = 0; n < income_frequency_size; n++)
            {
                const bool is_selected = (*curr_income_frequency == n);
                if (ImGui::Selectable(income_frequency[n], is_selected))
                {
                    *curr_income_frequency = n;
                }
                if (is_selected)
                {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }

        // current do not have additional withholdings option
    }

    void RenderAdjustments(int *adjustment_amount)
    {
        // enter adjustments amount
        ImGui::InputInt("Enter Adjustment Amount:", adjustment_amount);

        // add tooltip about adjustments/adjustment options (reference IRS)
    }

    void RenderDeductions(int *standard_deduction, int *itemized_deduction)
    {
        // Show standard deduction based off of income status
        if (ImGui::TreeNode("Standard"))
        {
            ImGui::SetNextItemOpen(true, ImGuiCond_Once);
            ImGui::Text("Standard Deduction: %d", *standard_deduction);
            ImGui::TreePop();
        }

        // Input itemized deduction, if itemized deduction is less than standard then use standard
        if (ImGui::TreeNode("Itemized"))
        {
            ImGui::SetNextItemOpen(true, ImGuiCond_Once);
            ImGui::InputInt("Itemized Deductions: ", itemized_deduction);
            ImGui::TreePop();
        }

        // Add tooltip about deduction options
    }

    void RederTaxCredits(int *tax_credits)
    {
        ImGui::InputInt("Enter Tax Credits", tax_credits);

        // Add tooltip about tax credit options
    }

    void GetTaxOwed(int *curr_income_status, int *adjusted_income, int *tax_owed)
    {
        if (*curr_income_status == 0 || *curr_income_status == 2)
        {
            if (*adjusted_income >= 0 && *adjusted_income < 10000)
            {
                *tax_owed = 310;
            }
            else if (*adjusted_income >= 10000 && *adjusted_income < 20000)
            {
                *tax_owed = 1630;
            }
            else if (*adjusted_income >= 20000 && *adjusted_income < 30000)
            {
                *tax_owed = 1880;
            }
            else if (*adjusted_income >= 30000 && *adjusted_income < 40000)
            {
                *tax_owed = 3720;
            }
            else if (*adjusted_income >= 40000 && *adjusted_income < 50000)
            {
                *tax_owed = 6570;
            }
            else if (*adjusted_income >= 50000 && *adjusted_income < 60000)
            {
                *tax_owed = 7700;
            }
            else if (*adjusted_income >= 60000 && *adjusted_income < 70000)
            {
                *tax_owed = 8460;
            }
            else if (*adjusted_income >= 70000 && *adjusted_income < 80000)
            {
                *tax_owed = 8660;
            }
            else if (*adjusted_income >= 80000 && *adjusted_income < 90000)
            {
                *tax_owed = 9260;
            }
            else if (*adjusted_income >= 90000 && *adjusted_income < 100000)
            {
                *tax_owed = 9460;
            }
            else if (*adjusted_income >= 100000 && *adjusted_income < 110000)
            {
                *tax_owed = 12610;
            }
            else if (*adjusted_income >= 110000 && *adjusted_income < 120000)
            {
                *tax_owed = 13430;
            }
        }
        else if (*curr_income_status == 1 || *curr_income_status == 4)
        {
            if (*adjusted_income >= 0 && *adjusted_income < 10000)
            {
                *tax_owed = 0;
            }
            else if (*adjusted_income >= 10000 && *adjusted_income < 20000)
            {
                *tax_owed = 930;
            }
            else if (*adjusted_income >= 20000 && *adjusted_income < 30000)
            {
                *tax_owed = 2920;
            }
            else if (*adjusted_income >= 30000 && *adjusted_income < 40000)
            {
                *tax_owed = 3320;
            }
            else if (*adjusted_income >= 40000 && *adjusted_income < 50000)
            {
                *tax_owed = 3720;
            }
            else if (*adjusted_income >= 50000 && *adjusted_income < 60000)
            {
                *tax_owed = 3760;
            }
            else if (*adjusted_income >= 60000 && *adjusted_income < 70000)
            {
                *tax_owed = 5750;
            }
            else if (*adjusted_income >= 70000 && *adjusted_income < 80000)
            {
                *tax_owed = 7750;
            }
            else if (*adjusted_income >= 80000 && *adjusted_income < 90000)
            {
                *tax_owed = 10600;
            }
            else if (*adjusted_income >= 90000 && *adjusted_income < 100000)
            {
                *tax_owed = 11600;
            }
            else if (*adjusted_income >= 100000 && *adjusted_income < 110000)
            {
                *tax_owed = 15260;
            }
            else if (*adjusted_income >= 110000 && *adjusted_income < 120000)
            {
                *tax_owed = 16330;
            }
        }
        else if (*curr_income_status == 3)
        {
            if (*adjusted_income >= 0 && *adjusted_income < 10000)
            {
                *tax_owed = 0;
            }
            else if (*adjusted_income >= 10000 && *adjusted_income < 20000)
            {
                *tax_owed = 1630;
            }
            else if (*adjusted_income >= 20000 && *adjusted_income < 30000)
            {
                *tax_owed = 2490;
            }
            else if (*adjusted_income >= 30000 && *adjusted_income < 40000)
            {
                *tax_owed = 2810;
            }
            else if (*adjusted_income >= 40000 && *adjusted_income < 50000)
            {
                *tax_owed = 5290;
            }
            else if (*adjusted_income >= 50000 && *adjusted_income < 60000)
            {
                *tax_owed = 6290;
            }
            else if (*adjusted_income >= 60000 && *adjusted_income < 70000)
            {
                *tax_owed = 9880;
            }
            else if (*adjusted_income >= 70000 && *adjusted_income < 80000)
            {
                *tax_owed = 11080;
            }
            else if (*adjusted_income >= 80000 && *adjusted_income < 90000)
            {
                *tax_owed = 12260;
            }
            else if (*adjusted_income >= 90000 && *adjusted_income < 100000)
            {
                *tax_owed = 12460;
            }
            else if (*adjusted_income >= 100000 && *adjusted_income < 110000)
            {
                *tax_owed = 15190;
            }
            else if (*adjusted_income >= 110000 && *adjusted_income < 120000)
            {
                *tax_owed = 16150;
            }
        }
    }

    void CalculateTax(int *tax_owed, int *curr_income_status, int *frequency, int *tax_per_pay_period, int *tax_credits, int *standard_deduction, int *itemized_deduction, int *income_amount, int *adjustment_amount, int *tax_percentage, int *adjusted_income, int *taxable_income)
    {
        // temp variables for calculating tax estimate
        static int temp;

        // set adjusted income amount
        *adjusted_income = *income_amount - *adjustment_amount;

        // numerical values for income frequency choice, could move this to separate function
        if (*frequency == 0)
        {
            temp = 52;
        }
        else if (*frequency == 1)
        {
            temp = 26;
        }
        else if (*frequency == 2)
        {
            temp = 24;
        }
        else if (*frequency == 3)
        {
            temp = 12;
        }

        // Calculate taxable income, could move this to separate function
        if (*income_amount < *standard_deduction || *adjusted_income < *standard_deduction)
        {
            *taxable_income = *adjusted_income;
        }
        else if (*income_amount > *standard_deduction)
        {
            if (*itemized_deduction <= *standard_deduction)
            {
                *taxable_income = *adjusted_income - *standard_deduction;
            }
            else if (*itemized_deduction > *standard_deduction)
            {
                *taxable_income = *adjusted_income - *itemized_deduction;
            }
        }

        // function to get annual tax owed amount
        GetTaxOwed(curr_income_status, adjusted_income, tax_owed);

        // deduct tax credits from tax owed, could move this to separate function
        if ((*tax_owed - *tax_credits) < 0)
        {
            *tax_owed = 0;
        }
        else
        {
            *tax_owed -= *tax_credits;
        }

        // calculate amount of tax owed per pay period
        *tax_per_pay_period = *tax_owed / temp;

        // calculate percentage per pay period
        *tax_percentage = 100 / ((*taxable_income / temp) / *tax_per_pay_period);
    }

    void RenderUI()
    {
        // Income variables
        const char *income_status[] = {"Single", "Married filing jointly", "Married filing separately", "Head of household", "Qualifying Widower"};
        static int current_income_status = 0;
        const char *income_status_preview = income_status[current_income_status];
        static int income_status_size = ARRAY_SIZE(income_status);

        // Withholdings variables
        const char *income_source[] = {"Salary", "Hourly", "Pension", "Social Security", "None of the Above"};
        const char *income_frequency[] = {"Weekly", "Every two weeks", "Twice Monthly", "Once a Month"};
        static int current_income_source = 0;
        static int current_income_frequency = 0;
        const char *income_source_preview = income_source[current_income_source];
        const char *income_frequency_preview = income_frequency[current_income_frequency];
        static int income_source_size = ARRAY_SIZE(income_source);
        static int income_frequency_size = ARRAY_SIZE(income_frequency);

        // taxes owed based on income variable
        static int income_amount = 0;
        static int tax_owed = 0;

        // adjustment amount
        static int adjustment_amount = 0;

        // Deductions variables
        static int standard_deduction;
        static int itemized_deduction = 0;

        // Tax credits variable
        static int tax_credits = 0;

        // Tax estimate result variables
        static int tax_per_pay_period = 0;
        static int tax_percentage;
        static int adjusted_income;
        static int taxable_income;

        // Render UI for application
        ImGui::Begin("Tax Estimator");
        if (ImGui::CollapsingHeader("Income"))
        {
            RenderIncome(income_status, &current_income_status, income_status_preview, income_status_size, &tax_owed, &standard_deduction, &income_amount, &adjustment_amount);
        }
        if (ImGui::CollapsingHeader("Withholdings"))
        {
            RenderWithholdings(income_frequency, income_source, &current_income_source, &current_income_frequency, income_source_preview, income_frequency_preview, income_source_size, income_frequency_size);
        }
        if (ImGui::CollapsingHeader("Adjustments"))
        {
            RenderAdjustments(&adjustment_amount);
        }
        if (ImGui::CollapsingHeader("Deductions"))
        {
            RenderDeductions(&standard_deduction, &itemized_deduction);
        }
        if (ImGui::CollapsingHeader("Tax Credits"))
        {
            RederTaxCredits(&tax_credits);
        }

        // Button to calculate tax estimate
        if (ImGui::Button("Calculate Estimate"))
        {
            CalculateTax(&tax_owed, &current_income_status, &current_income_frequency, &tax_per_pay_period, &tax_credits, &standard_deduction, &itemized_deduction, &income_amount, &adjustment_amount, &tax_percentage, &adjusted_income, &taxable_income);
        }

        // Application Disclaimer
        ImGui::SameLine();
        ImGui::Text("(?)");
        if (ImGui::IsItemHovered())
        {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
            ImGui::TextUnformatted("DISCLAIMER: This is an estimate, not a guaranteed amount you need to pay.  This application does not take into account other potential variables.  If you're unsure about something such as: What qualifies as an adjustment, what qualifies as a tax credit, or what qualifies as a deduction?, go to https://www.irs.gov/ to learn more.");
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }

        // End Result Text
        ImGui::Text("You owe approximately $%d in taxes per pay period.", tax_per_pay_period);
        ImGui::Text("That is approximately %d percent of your income per pay period.", tax_percentage);

        ImGui::End();
    }
}