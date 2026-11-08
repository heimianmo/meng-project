# 上手清单 · 已完成

> ✅ **2026-11-08 全部跑通**：代码已推送到 https://github.com/heimianmo/- （公开仓库，默认分支 main）。
> 当时网页又抽风了，所以直接用了账号里已有的空仓库，绕开「新建仓库」这一步。
> 下面保留完整步骤供复盘；**日常只看最后一节「以后每周就这四行」就够了**。

---

## 已经帮你做好的

| 事项 | 状态 |
|---|---|
| 生成 SSH 密钥对 | ✅ `C:\Users\Administrator\.ssh\id_ed25519` |
| 把 github.com 的 SSH 固定到 443 通道 | ✅ 已实测握手成功 |
| GitHub 端登记公钥 | ✅ `Hi heimianmo! You've successfully authenticated` |
| 安装 Git for Windows 2.56.0 | ✅ 装在 `D:\Git` |
| Git 全局配置 | ✅ main 分支、中文不乱码、Windows 换行、系统 OpenSSH、VS Code 编辑器 |
| 提交身份与远程地址 | ✅ `heimianmo` + noreply 邮箱；origin 指向 `git@github.com:heimianmo/-.git` |
| 首次提交并推送 | ✅ `65d0f56`，6 个文件，GitHub 端已核对 |

**为什么之前进不去**：`github.com` 网页的 443 通道是间歇性阻断的，不是你操作有误。
实测时它一开始全部 IP 超时，过几分钟再测又变成 1.2 秒正常打开。
CSDN 上教改 hosts 绑 IP 的办法已经失效——那些 IP 逐个测过，一个都不通。
而 Git 真正用来传代码的 SSH 通道一直是好的，所以下面走 SSH，绕开网页。

---

## 第 1 步：安装 Git

双击 `..\installers\Git-2.56.0.4-64-bit.exe`。向导十几页，**只有 3 页要改**：

| 页面 | 选什么 | 为什么 |
|---|---|---|
| Choosing the default editor | **Visual Studio Code** | 默认 Vim 退出要敲 `:wq`，新手常被卡住 |
| Adjusting your PATH environment | **中间那项**（带 Recommended） | 选第一项，CMD / PowerShell 里就用不了 git |
| Choosing the SSH executable | **Use external OpenSSH** | 和已经配好的 `~/.ssh/config` 保持一致 |

其余全部保持默认直接 Next：
- Adjusting the name of the initial branch：填 `main`（不填也没关系，已全局配好）
- HTTPS backend 选 OpenSSL；换行符选第一项（Checkout Windows-style）
- terminal 选 MinTTY；git pull 选 Fast-forward or merge
- credential helper 选 Git Credential Manager；extra options 保持默认

装完**关掉所有终端窗口再重新打开**，然后在任意终端里验证：

```bash
git --version
```

能显示版本号就成功了。

## 第 2 步：告诉 Git 你是谁

这两行必须换成你自己的信息，邮箱要和你注册 GitHub 时用的**完全一致**：

```bash
git config --global user.name "你的名字或昵称"
git config --global user.email "你的注册邮箱"
```

确认一下：

```bash
git config --global --list
```

## 第 3 步：先试一次 SSH 通道

```bash
ssh -T git@github.com
```

现在大概率会显示 `Permission denied (publickey)`。
**这不是报错，是预期结果**：说明线路已经打通了，只是 GitHub 还不认识你这把钥匙。下一步就是去登记。

## 第 4 步：打开网页，登录或注册

访问 `github.com`。**网页现在是通的，但这是窗口期，建议优先把注册和加公钥这两步做完**，
因为只有这两步必须依赖网页，之后所有操作都走 SSH，不再受网页影响。

如果又打不开，看本文最后的「网页又抽风了」。

## 第 5 步：把公钥交给 GitHub

复制下面这一整行：

```
ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIJFx2B7MHE/QfKqtfBpgc1qpAn80ZAdaf/NxiMXna78z github-chengde
```

网页上：右上角头像 → **Settings** → 左侧 **SSH and GPG keys** → **New SSH key**
→ Title 随便写（比如「我的笔记本」）→ 把上面整行贴进 Key → **Add SSH key**。

> 公钥（`id_ed25519.pub`）可以公开，私钥（`id_ed25519`）**永远不要发给任何人、也不要上传**。

## 第 6 步：再验证一次

```bash
ssh -T git@github.com
```

看到 `Hi 你的用户名! You've successfully authenticated, but GitHub does not provide shell access.`
就彻底通了。后面 clone、push、pull 都不会再受网页抽风影响。

## 第 7 步：新建空仓库 —— 这步跳过了

原计划打开 https://github.com/new 建 `medical-informatics-starter`，但当时网页整站超时。
账号里本来就有一个空的公开仓库 `heimianmo/-`，直接用了它，**不需要新建**。

## 第 8 步：推送 —— 已完成

实际执行并成功的命令：

```bash
git remote set-url origin git@github.com:heimianmo/-.git
git push -u origin main
```

返回 `* [new branch] main -> main`，`git status -sb` 显示 `## main...origin/main`。
GitHub 端已核对：`.gitignore`、`README.md`、`GIT-CHEATSHEET.md`、`SETUP-GUIDE.md`、
`data/`、`examples/` 全部存在，默认分支 main。

**到这一步，整套循环就跑通了。**

### 想把仓库名改得正经一点（可选）

等网页恢复，打开 https://github.com/heimianmo/-/settings → 最上面 Repository name
→ 改成 `medical-informatics-starter` → 点 Rename。代码和提交历史都会保留。
改完回来更新一下本地地址：

```bash
git remote set-url origin git@github.com:heimianmo/medical-informatics-starter.git
```

---

## 以后每周就这四行

```bash
git status
git add .
git commit -m "这周做了什么"
git push
```

忘了命令就翻 `GIT-CHEATSHEET.md`。

## 网页又抽风了怎么办

实测记录（2026-11-08）：19:46 时 `github.com` 的 5 个常用 IP 全部超时；
19:54 之后首页和登录页恢复到 1.2 秒打开，但 `/settings/keys` 又超时了一次。
**同一个网站、不同页面、不同时刻结果都不一样**，这就是间歇性阻断的典型表现。
所以你之前「第一次很轻松，后面怎么弄都不行」真的不是操作问题。

1. **先别慌**：网页打不开，不影响 clone / push / pull，它们走的是 SSH，照常干活。
2. 想稳一点就装 **Watt Toolkit**（微软商店直接搜，或访问 `steampp.net`），打开后开启 GitHub 加速。它是免费的开源工具，做本地反向代理，是国内学生最常用的方案。
3. 临时应急：换个浏览器、等几分钟重试、或者连手机热点试试——本来就是间歇性的，往往过一会儿自己就通了。
4. 别再照着改 hosts 的教程折腾了，那条路现在是死路。

## 顺手领一下学生福利

用学校邮箱在 GitHub 上做完学生认证后，搜 **GitHub Student Developer Pack**，
能免费用 Copilot、部分云服务和开发工具。对还在读书的你来说挺划算。

## 两条专业相关的提醒

- **绝不上传真实患者数据**：病历、DICOM 影像、带住院号的表格都不行。公开仓库等于公开发布，而且 Git 历史删不干净。`.gitignore` 已经帮你挡了常见格式，但习惯更重要。
- **练习一律用公开数据集或虚构数据**，本仓库 `data/vitals_sample.csv` 就是虚构的。
