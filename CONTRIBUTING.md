> [!WARNING]
> AI generated issues and PRs will be denied. I don't want QuickOverflow to be vibe developed. Feel free to use LLMs to fix bugs or critical errors but rest of the code needs to be human written.

Interested in contributing to QuickOverflow? Here's some resources to get you started

# Table of Contents

- ![The Idea Behind QuickOverflow](https://github.com/SpaciousCoder78/QuickOverflow/edit/main/CONTRIBUTING.md#the-idea-behind-quickoverflow)
- ![AI Policy](https://github.com/SpaciousCoder78/QuickOverflow/edit/main/CONTRIBUTING.md#ai-policy)
- ![Code of Conduct](https://github.com/SpaciousCoder78/QuickOverflow/edit/main/CONTRIBUTING.md#code-of-conduct)
- ![Asking Questions](https://github.com/SpaciousCoder78/QuickOverflow/edit/main/CONTRIBUTING.md#asking-questions)
- ![Drafting an Issue](https://github.com/SpaciousCoder78/QuickOverflow/edit/main/CONTRIBUTING.md#drafting-an-issue)
- ![Contributing to Code](https://github.com/SpaciousCoder78/QuickOverflow/edit/main/CONTRIBUTING.md#contributing-to-code)
- ![Code Documentation Guidelines](https://github.com/SpaciousCoder78/QuickOverflow/edit/main/CONTRIBUTING.md#code-documentation-guidelines)
- ![Drafting a Pull Request](https://github.com/SpaciousCoder78/QuickOverflow/edit/main/CONTRIBUTING.md#drafting-a-pull-request)
- ![Code Review Guidelines](https://github.com/SpaciousCoder78/QuickOverflow/edit/main/CONTRIBUTING.md#code-review-guidelines)
- ![Credits](https://github.com/SpaciousCoder78/QuickOverflow/edit/main/CONTRIBUTING.md#credits)

## The Idea Behind QuickOverflow

I got the idea for this software when I was dealing with loads of errors running other repos at work and having to copy paste errors into google and then searching felt tedious. Hence, I came up with an idea to automate this. 

I initially started this project and expected it to be a 1 hour project since I was just forking ghz-sh shell project for this one but one of the dependencies was written in Python2 which has been deprecated a long time ago. 

Hence came PyOverflow3 Python Library which powers QuickOverflow.

I don't believe in AI coding agents and the garbage they generate hence I always rely on the good old Google and StackOverflow, hence I went ahead with putting my time into developing this project. 

<i><b> Fun Fact: </b> QuickOverflow's development was so quick (pun intended) that I got to v2.0.0 within 24 hours of creating the repository with minimal reliance on LLMs </i>

Had I ever relied even a bit too much on LLMs, I would've never finished this project.

## AI Policy

If you took your time and read the previous section then you might have gotten some idea about the AI policy that I would like to follow for this project.

QuickOverflow's development must have minimal or no AI use as the entire project's goal is to drive people away from using unreliable and faulty AI Coding Agents.

Vibe coding is strictly banned for this project and any PRs or Issues found to be vibe coded will be denied and multiple repetitions will result in a ban from the repository.

You're allowed to use LLMs/AI only for fixing nasty bugs or critical errors but rest of the development must be human generated.

## Code of Conduct

### Our Pledge

In the interest of fostering an open and welcoming environment, we as contributors and maintainers pledge to making participation in our project and our community a harassment-free experience for everyone, regardless of age, body size, disability, ethnicity, sex characteristics, gender identity and expression, level of experience, education, socio-economic status, nationality, personal appearance, race, religion, or sexual identity and orientation.

### Our Standards

Examples of behavior that contributes to creating a positive environment include:

  -  Using welcoming and inclusive language
  -  Being respectful of differing viewpoints and experiences
  -  Gracefully accepting constructive criticism
  -  Focusing on what is best for the community
  -  Showing empathy towards other community members

Examples of unacceptable behavior by participants include:

  - The use of sexualized language or imagery and unwelcome sexual attention or advances
  -  Trolling, insulting/derogatory comments, and personal or political attacks
  -  Public or private harassment
  -  Publishing others' private information, such as a physical or electronic address, without explicit permission
  -  Other conduct which could reasonably be considered inappropriate in a professional setting

### Our Responsibility

Project maintainers are responsible for clarifying the standards of acceptable behavior and are expected to take appropriate and fair corrective action in response to any instances of unacceptable behavior.

Project maintainers have the right and responsibility to remove, edit, or reject comments, commits, code, wiki edits, issues, and other contributions that are not aligned to this Code of Conduct, or to ban temporarily or permanently any contributor for other behaviors that they deem inappropriate, threatening, offensive, or harmful.

## Asking Questions

Please use the <a href="https://github.com/SpaciousCoder78/QuickOverflow/discussions"> Discussion Forums</a> for asking questions.

## Drafting an issue

You can draft an issue for a bug, feature request or something that you wish to see at our <a href="https://github.com/SpaciousCoder78/QuickOverflow/issues"> Issues</a> page.

## Contributing to Code

Please ensure you have the following requirements to contribute to code:

- Linux Based Operating System (preferably Ubuntu/Debian Distro)
- A Github Account
- Git
- Ability to use Google and StackOverflow

Having knowledge in these things is recommended for code contributions:

- C Programming Language
- Basics of Operating System Shells and Process Communication (optional)
- Python3
- Bash Scripting
- Build Tools like make
- Experience with Terminal

### Getting Started with Code Contribution

- Draft an issue mentioning the change or fix that you want to make in the <a href="https://github.com/SpaciousCoder78/QuickOverflow/issues"> Issues</a> page
- Clone the development branch of this repository
```sh
$ git clone -b development --single-branch https://github.com/SpaciousCoder78/QuickOverflow.git
```
- Open the cloned directory
```sh
$ cd QuickOverflow
```
- Run `install.sh`
```sh
$ sh install.sh
```
- Make your changes, test them and open a pull request mentioning the Issue number

## Code Documentation Guidelines

I take documentation very seriously and each and every function/implementation in this codebase is well documented.

Examples of Good Documentation

```c
//Including header files
#include <stdio.h>
// A function performing product of 2 numbers
void main(){
  //given 2 hard coded numbers
  int a = 30;
  int b = 2;
  int prod = a*b; //multiply
  printf("Product: %d",&prod); //print result
}
```

## Drafting a Pull Request

For drafting a PR, push your changes into `development` branch and open a PR, mentioning the changes you made.

Use the following conventions for naming your PRs.

- feat: for adding a new feature
- fix: for fixing a bug
- docs: for adding documentation
- test: for testing and making some changes
- build: for making any changes to the build system

Example of a well written PR title:

feat: Added a new feature to enable something

## Code Review Guidelines

  -  Review the code, not the author. Look for and suggest improvements without disparaging or insulting the author. Provide actionable feedback and explain your reasoning.

  -  You are not your code. When your code is critiqued, questioned, or constructively criticized, remember that you are not your code. Do not take code review personally.

  -  Always do your best. No one writes bugs on purpose. Do your best, and learn from your mistakes.

  -  Kindly note any violations to the guidelines specified in this document.

## Credits

I will be crediting contributors here for their contributions.
