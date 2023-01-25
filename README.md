# Application Description

A tax estimator application for the 2023 tax year based off the tax estimator on the IRS website.  Made using C++, Dear ImGui, and Microsoft Visual Studio.  Aimed for a streamlined approach to calculating an estimate of taxes owed for the year.

> This is created with DirectX 12 in mind.  If this application does not work for you, this could be a potential reason why.

# Technologies Used

- C++
- Microsoft Visual Studio 2022
- Dear ImGui

# Installation

1. Open your terminal and navigate to your desired directory where you want to store this repository by using `cd <YOUR DIRECTORY HERE>`.
2. On this GitHub repository, click on the `Code` dropdown menu and either click on `HTTPS` or `SSH` depending on what you're using.
    > You can either click the link which will highlight the `HTTPS` URL or `SSH` key and copy it or click on the icon next to it which will copy it into your clipboard.
3. Fork and Clone this repository to your machine using `git clone <PASTE YOUR SSH OR HTTP HERE>`.
4. Navigate into your newly cloned directory.
    > The directory should be named `Tax-Estimator`.  The command you should run should look like this: `cd Tax-Estimator`.
5. Now you can open the application by navigating to it using your `File Explorer` or equivalent.
    > You can use the path written on your console for an easy time navigating.
6. Open the application.
    > You will have to manually adjust the size of the window to your liking.

# Current Application State

![image](https://user-images.githubusercontent.com/65789692/214377841-14aeba52-ee69-4a8e-afe3-cd352b30e93f.png)
![image](https://user-images.githubusercontent.com/65789692/214378161-b2ba993b-9578-4603-b1ea-2b5879ec477f.png)

# Future Improvements

- Connect with a backend database to store profiles and prior tax estimates.
- Update the UI to have a base window size so the user doesn't have to manually adjust it.
- Add more options related to income, withholdings, adjustments, deductions, and tax credits.
- Add more tooltips regarding the options available.
- Add more tooltips about what each option mean and how to qualify for it.

# Contribution Guidelines

## How to Identify Bugs

> If you identify bugs, submit an issue on the GitHub repository.  Please detail the bug in your issue by: describe the bug (any error messages or unexpected behavior) and the steps necessary to replicate the bug.  If you know how to fix it, feel free to note the methods you would use.  You could also submit a pull request with the suggested code to fix it.

## Known Bugs

- Currently, the choice the user makes regarding income source does not affect the estimate result.

# References

Dear IMGUI:
- https://github.com/ocornut/imgui/tree/master