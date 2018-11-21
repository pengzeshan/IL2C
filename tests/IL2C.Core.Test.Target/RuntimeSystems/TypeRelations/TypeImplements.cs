﻿using System;
using System.ComponentModel;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    public interface IInterfaceType1
    {
        string GetStringFromInt32(int value);
    }

    public class InstanceImplementType : IInterfaceType1
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 100;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public interface IInterfaceType2
    {
        string GetStringFromInt64(long value);
    }

    public class InstanceMultipleImplementType : IInterfaceType1, IInterfaceType2
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs1 = 100;
        private readonly long rhs2 = 200;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs1).ToString();
        }

        public string GetStringFromInt64(long value)
        {
            return (value + rhs2).ToString();
        }
    }

    public interface IInterfaceType3
    {
        string GetStringFromInt32(int value);
    }

    public class InstanceMultipleImplementUnifiedType : IInterfaceType1, IInterfaceType3
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs = 100;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs).ToString();
        }
    }

    public class InstanceMultipleImplementExplicitlyType : IInterfaceType1, IInterfaceType3
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs1 = 100;
        private readonly int rhs3 = 200;

        string IInterfaceType1.GetStringFromInt32(int value)
        {
            return (value + rhs1).ToString();
        }

        string IInterfaceType3.GetStringFromInt32(int value)
        {
            return (value + rhs3).ToString();
        }
    }

    public class InstanceMultipleImplementCombinationType : IInterfaceType1, IInterfaceType3
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs1 = 100;
        private readonly int rhs3 = 200;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs1).ToString();
        }

        string IInterfaceType3.GetStringFromInt32(int value)
        {
            return (value + rhs3).ToString();
        }
    }

    public interface IInterfaceType4
    {
        string GetStringFromInt32(int value);
        string GetStringFromInt64(long value);
    }

    public class InstanceMultipleCombinedImplementType : IInterfaceType4
    {
        // It's the instance field, referrer from the method at same type.
        private readonly int rhs1 = 100;
        private readonly long rhs2 = 200;

        public string GetStringFromInt32(int value)
        {
            return (value + rhs1).ToString();
        }

        string IInterfaceType4.GetStringFromInt64(long value)
        {
            return (value + rhs2).ToString();
        }
    }

    [TestId("TypeRelations")]
    [TestCase("223", "InstanceImplement", 123, IncludeTypes = new[] { typeof(InstanceImplementType), typeof(IInterfaceType1) })]
    [TestCase("223", "InstanceImplementFromInterface", 123, IncludeTypes = new[] { typeof(InstanceImplementType), typeof(IInterfaceType1) })]
    [TestCase("223", "InstanceMultipleImplement1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementType), typeof(IInterfaceType1), typeof(IInterfaceType2) })]
    [TestCase("223", "InstanceMultipleImplementFromInterface1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementType), typeof(IInterfaceType1), typeof(IInterfaceType2) })]
    [TestCase("323", "InstanceMultipleImplement2", 123L, IncludeTypes = new[] { typeof(InstanceMultipleImplementType), typeof(IInterfaceType1), typeof(IInterfaceType2) })]
    [TestCase("323", "InstanceMultipleImplementFromInterface2", 123L, IncludeTypes = new[] { typeof(InstanceMultipleImplementType), typeof(IInterfaceType1), typeof(IInterfaceType2) })]
    [TestCase("223", "InstanceMultipleImplementUnified1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementUnifiedType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleImplementUnifiedFromInterface1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementUnifiedType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleImplementUnifiedFromInterface3", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementUnifiedType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleImplementCombination", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementCombinationType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleImplementCombinationFromInterface1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementCombinationType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("323", "InstanceMultipleImplementCombinationFromInterface3", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementCombinationType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleImplementExplicitlyFromInterface1", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementExplicitlyType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("323", "InstanceMultipleImplementExplicitlyFromInterface3", 123, IncludeTypes = new[] { typeof(InstanceMultipleImplementExplicitlyType), typeof(IInterfaceType1), typeof(IInterfaceType3) })]
    [TestCase("223", "InstanceMultipleCombinedImplement", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementType), typeof(IInterfaceType4) })]
    [TestCase("223", "InstanceMultipleCombined1ImplementFromInterface4", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementType), typeof(IInterfaceType4) })]
    [TestCase("323", "InstanceMultipleCombined2ImplementFromInterface4", 123, IncludeTypes = new[] { typeof(InstanceMultipleCombinedImplementType), typeof(IInterfaceType4) })]
    public sealed class TypeImplements
    {
        public static string InstanceImplement(int value)
        {
            var inst = new InstanceImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceImplementFromInterface(int value)
        {
            IInterfaceType1 inst = new InstanceImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplement1(int value)
        {
            var inst = new InstanceMultipleImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementFromInterface1(int value)
        {
            IInterfaceType1 inst = new InstanceMultipleImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplement2(long value)
        {
            var inst = new InstanceMultipleImplementType();
            return inst.GetStringFromInt64(value);
        }

        public static string InstanceMultipleImplementFromInterface2(long value)
        {
            IInterfaceType2 inst = new InstanceMultipleImplementType();
            return inst.GetStringFromInt64(value);
        }

        public static string InstanceMultipleImplementUnified1(int value)
        {
            var inst = new InstanceMultipleImplementUnifiedType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementUnifiedFromInterface1(int value)
        {
            IInterfaceType1 inst = new InstanceMultipleImplementUnifiedType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementUnifiedFromInterface3(int value)
        {
            IInterfaceType3 inst = new InstanceMultipleImplementUnifiedType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementCombination(int value)
        {
            var inst = new InstanceMultipleImplementCombinationType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementCombinationFromInterface1(int value)
        {
            IInterfaceType1 inst = new InstanceMultipleImplementCombinationType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementCombinationFromInterface3(int value)
        {
            IInterfaceType3 inst = new InstanceMultipleImplementCombinationType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementExplicitlyFromInterface1(int value)
        {
            IInterfaceType1 inst = new InstanceMultipleImplementExplicitlyType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleImplementExplicitlyFromInterface3(int value)
        {
            IInterfaceType3 inst = new InstanceMultipleImplementExplicitlyType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombinedImplement(int value)
        {
            var inst = new InstanceMultipleCombinedImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombined1ImplementFromInterface4(int value)
        {
            IInterfaceType4 inst = new InstanceMultipleCombinedImplementType();
            return inst.GetStringFromInt32(value);
        }

        public static string InstanceMultipleCombined2ImplementFromInterface4(long value)
        {
            IInterfaceType4 inst = new InstanceMultipleCombinedImplementType();
            return inst.GetStringFromInt64(value);
        }
    }
}
