# STM32F4 Jenkins CI

[![C](https://img.shields.io/badge/C-95%2F99%2F11%2F17%2F23-blue)](https://en.cppreference.com/index.html)
[![License](https://img.shields.io/badge/license-MIT-green)](https://github.com/abelbarreira/stm32f4_jenkins_ci/blob/main/LICENSE)
[![Pull Requests Welcome](https://img.shields.io/badge/pull%20requests-welcome-brightgreen.svg)](https://github.com/abelbarreira/stm32f4_jenkins_ci/blob/main/.github/CONTRIBUTING.md)

## About The Project

STM32F4 Jenkins CI project deploys **[Jenkins](https://www.jenkins.io/)** local server with a `STM32F407G-DISC1` discovery board connected in order to build, load (flash) using [OpenOCD](https://openocd.org/) and execute **[Unity](https://www.throwtheswitch.org/unity)** tests.

This is is based in [STM32F4 Basic](https://github.com/abelbarreira/stm32f4_basic).

## Environment

This environment is ready to work with [Git & Git Bash](https://git-scm.com/downloads) scripting with [Visual Studio Code](https://code.visualstudio.com/) using following profile:

- `tools/vscode/stm32f4_socrates.code-profile`

## Setup

The project will probably end up with a [Docker](https://www.docker.com/) container to centralize the full setup. In addition, here is the local setup environment:

- `scripts/setup_linux.sh`, or similar setup for Windows (refer to [setup_windows](docs/stm32_board/setup_windows.md))
- `scripts/setup_python.sh`
  - Requires [`pyenv`](https://github.com/pyenv/pyenv)
- `scripts/stm32f4_drivers_add_or_update_subs.sh`
- `scripts/unity_add_or_update_sub.sh` (for Unity Testing)
- [Setup Jenkins](docs/jenkins.md)

## Documentation

Refer to [SUMMARY](docs/SUMMARY.md).

## Contributing

If you have suggestions for how Open Source Projects Template could be improved, or want to report a bug, open an issue! We'd love all and any contributions.

For more, check out the [Contributing Guide](.github/CONTRIBUTING.md).

## License

MIT License

Copyright (c) 2025 abelbarreira

For more, check out the [License File](LICENSE).

## AI-Powered Collaboration

This project is being developed with support and guidance from [ChatGPT](https://chatgpt.com/) and [GitHub Copilot](https://github.com/copilot).

Collaboration started in August 2025.
