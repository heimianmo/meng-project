"""生命体征数据入门示例 —— 只用 Python 标准库，不需要装任何包。

演示医学信息处理最基础的一步：把数据读进来、算统计量、按阈值标出异常。
数据是虚构的，仅用于教学。判定阈值也只是演示，不是临床标准。

运行：
    python examples/vitals_summary.py
"""

import csv
import sys
from pathlib import Path
from statistics import mean

if hasattr(sys.stdout, "reconfigure"):
    try:
        sys.stdout.reconfigure(encoding="utf-8")
    except Exception:
        pass

DATA_FILE = Path(__file__).resolve().parent.parent / "data" / "vitals_sample.csv"

# 字段 -> (下限, 上限, 中文名)。超出范围就标记为异常。
RULES = {
    "heart_rate": (60, 100, "心率"),
    "systolic": (90, 140, "收缩压"),
    "spo2": (95, 100, "血氧"),
}


def load_records(path):
    """从 CSV 读出记录，返回字典列表。"""
    with path.open(encoding="utf-8-sig", newline="") as f:
        return list(csv.DictReader(f))


def find_issues(row):
    """按阈值检查一条记录，返回异常描述列表。"""
    issues = []
    for field, (low, high, label) in RULES.items():
        value = float(row[field])
        if value < low or value > high:
            issues.append(f"{label}{value:g}")
    return issues


def main():
    rows = load_records(DATA_FILE)
    print(f"共 {len(rows)} 条记录（虚构示例数据，非真实患者）\n")

    header = f"{'编号':<6} {'时间':<18} {'心率':>5} {'收缩压':>7} {'血氧':>5}  异常标记"
    print(header)
    print("-" * 68)

    flagged = 0
    for row in rows:
        issues = find_issues(row)
        if issues:
            flagged += 1
        mark = "、".join(issues) if issues else "—"
        print(
            f"{row['record_id']:<6} {row['time']:<18} "
            f"{row['heart_rate']:>5} {row['systolic']:>7} {row['spo2']:>5}  {mark}"
        )

    print("-" * 68)
    hr = [float(r["heart_rate"]) for r in rows]
    spo2 = [float(r["spo2"]) for r in rows]
    print(f"平均心率：{mean(hr):.1f} 次/分（最低 {min(hr):g}，最高 {max(hr):g}）")
    print(f"平均血氧：{mean(spo2):.1f} %")
    print(f"异常记录：{flagged} 条 / 共 {len(rows)} 条")
    print("\n提示：把阈值改成课程要求的值，或加一个舒张压规则，就是一次不错的练习。")


if __name__ == "__main__":
    main()
