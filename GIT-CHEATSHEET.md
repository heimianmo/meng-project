# Git 常用命令速查（中文）

记不住很正常，用到就回来查。前 5 条覆盖 90% 的日常。

## 每天都要用的循环

```bash
git status                    # 看看现在改了哪些文件（最常用，随时敲）
git add .                     # 把所有改动放进"待提交区"
git add 文件名                 # 只放某一个文件
git commit -m "写清楚改了啥"   # 存一个版本，相当于存个存档点
git push                      # 上传到 GitHub
git pull                      # 把 GitHub 上的新内容拿下来
```

## 查看和对比

```bash
git log --oneline --graph     # 看提交历史，一行一条，带分支图
git diff                      # 看还没 add 的改动具体改了什么
git diff --cached             # 看已经 add、还没 commit 的改动
git remote -v                 # 看这个仓库连的是哪个远程地址
```

## 改错了怎么办（别慌，多数情况能救）

```bash
git restore 文件名             # 丢弃某个文件还没提交的改动
git restore --staged 文件名    # 把文件从待提交区撤回来（内容不丢）
git commit --amend -m "新说明" # 改上一条提交的说明文字
git reset --soft HEAD~1       # 撤销上一次提交，但改动都还在
```

> `git restore 文件名` 会真的丢掉你没提交的修改，用之前先看一眼 `git diff`。
> 已经 commit 过的东西几乎都能找回来，所以**养成勤 commit 的习惯反而是最安全的**。

## 远程仓库

```bash
git remote add origin git@github.com:你的用户名/仓库名.git
git push -u origin main        # 第一次推送，顺便绑定默认上游
git clone git@github.com:用户名/仓库名.git   # 把别人的项目下载下来
```

## 分支（做实验时用，不污染主线）

```bash
git branch                    # 看有哪些分支
git switch -c 试验分支          # 新建并切到一个分支
git switch main               # 切回主线
git merge 试验分支             # 把试验成果合回主线
```

## 几个容易踩的坑

- **commit 的说明别写"修改"**：三个月后你自己也看不懂。写"加入心率异常判定逻辑"。
- **一次 commit 只做一件事**：别把作业、笔记、随手改的 bug 塞进同一条。
- **push 前先 pull**：多人协作或者换过电脑时，能少很多冲突。
- **SSH 地址长这样**：`git@github.com:xxx/yyy.git`，不要用 `https://github.com/...`，
  后者在当前网络环境下走的是被卡住的网页通道。
